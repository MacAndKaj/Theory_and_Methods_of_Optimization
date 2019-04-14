#include <include/mainwindow.h>
#include <include/graph.h>
#include <include/functioninput.h>
#include <ui_mainwindow.h>
#include <iostream>
#include<QMessageBox>
#include<QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _ui->progressBar_computing->hide();
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

void MainWindow::setFunction(const std::string &function)
{
    std::cout << function << std::endl;
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
}
