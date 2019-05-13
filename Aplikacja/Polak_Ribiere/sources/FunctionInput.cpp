#include <map>
#include <string>
#include <optional>
#include <MainWindow.h>
#include <FunctionInput.h>
#include <ui_functioninput.h>
#include <iostream>

FunctionInput::FunctionInput(QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::FunctionInput)
{
    setUp();
}

FunctionInput::FunctionInput(MainWindow* mainWindow)
    : _ui(new Ui::FunctionInput)
    , _mainWindow(mainWindow)
{
    setUp();
}

void FunctionInput::setUp()
{
    _ui->setupUi(this);
    createComboBox();
    _ui->radioButton_chooseFunction->setChecked(true);
    _ui->lineEdit_function->setDisabled(true);
    connect(_ui->radioButton_chooseFunction, &QRadioButton::clicked, this
            , &FunctionInput::radioButtonChanged);
    connect(_ui->radioButton_inputFunction, &QRadioButton::clicked, this
            , &FunctionInput::radioButtonChanged);
    connect(_ui->buttonBox, &QDialogButtonBox::accepted, this, &FunctionInput::acceptFunction);
}

FunctionInput::~FunctionInput()
{
    delete _ui;
}

void FunctionInput::acceptFunction()
{
    if (_ui->radioButton_chooseFunction->isChecked())
    {
        _chosenFunction = _functionsSaver
            .getFunctionWithIndex(_ui->comboBox_functions->currentIndex());
    }
    else
    {
        _chosenFunction = _ui->lineEdit_function->text().toStdString();
    }
    accept();
}

void FunctionInput::createComboBox()
{
    for (const auto& functionPair: _functionsSaver.readFunctions())
    {
        if (functionPair.first.empty())
        {
            _ui->comboBox_functions->addItem({functionPair.second.c_str()});
        }
        else
        {
            auto function = functionPair.first + " (" + functionPair.second + ")";
            _ui->comboBox_functions->addItem(function.c_str());
        }
    }
}

void FunctionInput::radioButtonChanged()
{
    _ui->comboBox_functions->setDisabled(not _ui->radioButton_chooseFunction->isChecked());
    _ui->lineEdit_function->setDisabled(_ui->radioButton_chooseFunction->isChecked());
}

const std::string& FunctionInput::getChosenFunction() const
{
    return _chosenFunction;
}
