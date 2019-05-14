#include <iomanip>
#include <sstream>
#include <iostream>
#include <QMessageBox>
#include <QCloseEvent>
#include <QListWidget>
#include <MainWindow.h>
#include <FunctionInput.h>
#include <Graph.h>
#include <SSolution.hpp>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
    , _graph(nullptr)
    , _functionInput(nullptr)
    , _log(LoggersFactory::getLoggersFactory().getLogger("MainWindow"))
{
    _ui->setupUi(this);
    _ui->progressBar_computing->hide();
    _ui->pushButton_start->setDisabled(true);
    _ui->pushButton_show->setDisabled(true);

    std::stringstream strm;
    strm << std::scientific << defaultSolutionGradientError;
    _ui->lineEdit_gradientError->setText(strm.str().c_str());
    strm.str("");
    strm << std::scientific << defaultSolutionStepError;
    _ui->lineEdit_StepError->setText(strm.str().c_str());
    strm.str("");
    strm << std::scientific << defaultSolutionValueError;
    _ui->lineEdit_ValueError->setText(strm.str().c_str());
    _ui->doubleSpinBox_armijo->setValue(defaultArmijoMethodParameter);
    _ui->spinBox_iterations->setValue(defaultIterationsNumber);

    currentMethodChanged(1);
    connect(_ui->pushButton_start, &QPushButton::clicked, this, &MainWindow::startClicked);
    setupComboBox();
    _solver.setMethod(methodsVector[1].second);
}

MainWindow::~MainWindow() = default;

void MainWindow::closeEvent(QCloseEvent* event)
{
    QMessageBox::StandardButton resBtn =
        QMessageBox::question(this, QObject::tr("Exit!"), QObject::tr("Are you sure?\n"),
            QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes)
    {
        event->accept();
        return;
    }
    event->ignore();
}

void MainWindow::setFunction()
{
    auto function = _functionInput->getChosenFunction();
    _ui->label_chosenFunction->setText(function.c_str());
    unsigned int dimension = 0;
    while (function.find("x" + std::to_string(dimension + 1)) != std::string::npos)
    {
        ++dimension;
    }

    std::stringstream strm;
    strm << __FUNCTION__ << " to " << function << " with dimension " << dimension;
    _log << 'I' + strm.str();
    _solver.setFunction(dimension, function);
    disconnect(_functionInput, &FunctionInput::accepted, this, &MainWindow::setFunction);
    delete (_functionInput);
    startingPointEdit(dimension);
    _ui->pushButton_start->setDisabled(dimension == 0);
    _ui->pushButton_show->setDisabled(true);
}

void MainWindow::on_pushButton_show_clicked()
{
    if (_graph != nullptr) _graph->close();
    _graph = new Graph(_solver.getFunction(), _solver.getSolution());
    _graph->exec();
}

void MainWindow::on_pushButton_chooseFunction_clicked()
{
    _functionInput = new FunctionInput();
    connect(_functionInput, SIGNAL(accepted()), this, SLOT(setFunction()));
    _functionInput->exec();

}

void MainWindow::startClicked()
{
    connect(&_solver, SIGNAL(iterationDone(
                                 const FunctionInPointParameters&)), this, SLOT(iterationDone(
                                                                                    const FunctionInPointParameters&)));
    std::vector<double> point;
    for (const auto& lineEdit : _lineEdits)
    {
        point.push_back(lineEdit->text().toDouble());
    }
    SVector startPoint(point);
    _ui->textBrowser->clear();
    _ui->textBrowser->clearHistory();

    _solver.setStartPoint(startPoint);
    startComputing();

    disconnect(&_solver, SIGNAL(iterationDone(
                                    const FunctionInPointParameters&)), this, SLOT(iterationDone(
                                                                                       const FunctionInPointParameters&)));
    _ui->pushButton_show->setEnabled(_solver.getProblemDimension() == 2);
}

void MainWindow::startComputing()
{
    IterationMethodsParameters params(
        _ui->lineEdit_gradientError->text().toDouble(), _ui->lineEdit_StepError->text().toDouble()
        , _ui->lineEdit_ValueError->text().toDouble(), _ui->doubleSpinBox_armijo->value()
        , static_cast<unsigned int>(_ui->spinBox_iterations->value()));
    _solver.setAlgorithmParameters(params);

    _solver.startComputing();

}

void MainWindow::setupComboBox()
{
    for (const auto& pair : methodsVector)
    {
        _ui->comboBox_methods->addItem(pair.first);
    }

    _ui->comboBox_methods->setCurrentIndex(1);
    connect(_ui->comboBox_methods, SIGNAL(
                                       currentIndexChanged(int)), this, SLOT(currentMethodChanged(
        int)));
    _log << 'I' + std::string(__FUNCTION__) + " succesfully!";
}

void MainWindow::currentMethodChanged(int index)
{
    if (index == 0) //method_unknown
    {
        _ui->pushButton_chooseFunction->setDisabled(true);
    }
    else if (not _ui->pushButton_chooseFunction->isEnabled())
    {
        _ui->pushButton_chooseFunction->setDisabled(false);
    }
    _log << std::string(__FUNCTION__) + " to " + methodsVector[index].first.toStdString();
}

void MainWindow::iterationDone(const FunctionInPointParameters& parameters)
{
    _ui->textBrowser->append((parameters.toString() + '\n').c_str());
}

void MainWindow::startingPointEdit(unsigned int dimension)
{
    if (not _layouts.empty())
    {
        for (auto&& object : _lineEdits)
        {
            delete (object);
        }
        _lineEdits.clear();
        for (auto&& object : _labels)
        {
            delete (object);
        }
        _labels.clear();
        for (auto&& layout : _layouts)
        {
            delete (layout);
        }
        _layouts.clear();
        qDeleteAll(_ui->horizontalLayout_5->children());
    }

    for (unsigned int i = 0; i < dimension; ++i)
    {
        auto layout = new QFormLayout;
        _layouts.push_back(layout);
        layout->setHorizontalSpacing(1);
        layout->setVerticalSpacing(2);
        auto labelItem = new QLabel(("x" + std::to_string(i + 1)).c_str());
        layout->addWidget(labelItem);
        _labels.push_back(labelItem);
        auto lineEditItem = new QLineEdit();
        layout->addWidget(lineEditItem);
        _lineEdits.push_back(lineEditItem);
        _ui->horizontalLayout_5->addLayout(layout);
    }
}
