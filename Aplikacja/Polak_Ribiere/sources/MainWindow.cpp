#include <sstream>
#include <iostream>
#include <QMessageBox>
#include <QCloseEvent>
#include <ui_mainwindow.h>
#include <MainWindow.h>
#include <FunctionInput.h>
#include <Graph.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
    , _log(LoggersFactory::getLoggersFactory().getLogger("MainWindow"))
{
    _ui->setupUi(this);
    _ui->progressBar_computing->hide();
    _ui->pushButton_chooseFunction->setDisabled(true);
    _ui->pushButton_start->setDisabled(true);

    connect(_ui->pushButton_start, &QPushButton::clicked, this, &MainWindow::startClicked);
    setupComboBox();
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

void MainWindow::setFunction(const std::string& function)
{
    unsigned int dimension = 0;
    while (function.find("x" + std::to_string(dimension + 1)) != std::string::npos)
    {
        ++dimension;
    }

    std::stringstream strm;
    strm << __FUNCTION__ << " to " << function << " with dimension " << dimension;
    _log << 'I' + strm.str();
    _solver.setFunction(dimension, function);
}

void MainWindow::on_pushButton_StopShow_clicked()
{
    _graph = std::make_unique<Graph>();
    _graph->exec();
}

void MainWindow::on_pushButton_chooseFunction_clicked()
{
    _functionInput = std::make_unique<FunctionInput>();
    _functionInput->exec();
    setFunction(_functionInput->getChosenFunction());
}

void MainWindow::startClicked()
{
    _ui->listWidget->addItems({"first item", "second item"});
}

void MainWindow::startComputing()
{

}

void MainWindow::setupComboBox()
{
    for (const auto& pair : methodsMap)
    {
        _ui->comboBox_methods->addItem(pair.first);
    }

    _ui->comboBox_methods->setCurrentIndex(0);
    connect(_ui->comboBox_methods, SIGNAL(currentIndexChanged(int)),
        this, SLOT(currentMethodChanged(int)));
    _log << 'I' + std::string(__FUNCTION__) + " succesfully!";
}

void MainWindow::currentMethodChanged(int index)
{
    if (index == 0) //method_unknown
    {
        _ui->pushButton_chooseFunction->setDisabled(true);
        _ui->pushButton_start->setDisabled(true);
    }
    else if (not _ui->pushButton_chooseFunction->isEnabled())
    {
        _ui->pushButton_chooseFunction->setDisabled(false);
        _ui->pushButton_start->setDisabled(false);
    }
    _solver.setMethod(methodsMap[index].second);
    _log << std::string(__FUNCTION__) + " to " + methodsMap[index].first.toStdString();
}