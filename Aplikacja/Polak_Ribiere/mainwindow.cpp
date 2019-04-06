#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "standardfunctionsdefinitions.h"
#include<QMessageBox>
#include<QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _ui->progressBar_computing->hide();
    createComboBox();
}

MainWindow::~MainWindow()
{
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, QObject::tr("Exit!"),
                                                                QObject::tr("Are you sure?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
        event->accept();
        return;
    }
    event->ignore();
}





void MainWindow::on_pushButton_StopShow_clicked()
{
    _graph = std::make_unique<Graph>();
    _graph->show();
}

void MainWindow::createComboBox()
{
    QStringList listOfFunctions("-");
    listOfFunctions.reserve(listOfFunctions.size());
    std::for_each(standardFunctions.begin(),standardFunctions.end(),[&listOfFunctions](const std::string& fun){
       listOfFunctions.append(fun.c_str());
    });
    _ui->comboBox_knownFunctions->addItems(listOfFunctions);
}
