#include <map>
#include <string>
#include <optional>
#include <include/mainwindow.h>
#include <include/functioninput.h>
#include <ui_functioninput.h>
#include <iostream>

std::vector<std::pair<std::string,std::string>> standardFunctions=
{
    {"","x1^4+x2^4-0.62*x1^2-0.62*x2^2"},
    {"","100*(x2-x1^2)^2+(1-x1)^2"}
};

FunctionInput::FunctionInput(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::FunctionInput)
{
    _ui->setupUi(this);
    createComboBox();
    connect(_ui->buttonBox,&QDialogButtonBox::accepted,this,&FunctionInput::acceptFunction);
    _ui->radioButton_chooseFunction->setChecked(true);
}


FunctionInput::FunctionInput(MainWindow *mainWindow)
    : _ui(new Ui::FunctionInput)
    , _mainWindow(mainWindow)
{
    _ui->setupUi(this);
    createComboBox();
    connect(_ui->buttonBox,&QDialogButtonBox::accepted,this,&FunctionInput::acceptFunction);
    _ui->radioButton_chooseFunction->setChecked(true);
}

void FunctionInput::acceptFunction()
{
    if(_ui->radioButton_chooseFunction->isChecked())
    {
        _mainWindow->setFunction(_ui->comboBox_functions->currentText().toStdString());
    }
    else if(_ui->radioButton_inputFunction->isChecked())
    {
        _mainWindow->setFunction(_ui->lineEdit_function->text().toStdString());
    }
    else
    {
        std::cout << "nie wybrano" << std::endl;
    }
}

void FunctionInput::createComboBox()
{
    for (const auto& functionPair: standardFunctions)
    {
        if(functionPair.first.empty())
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


FunctionInput::~FunctionInput()
{
    delete _ui;
}

