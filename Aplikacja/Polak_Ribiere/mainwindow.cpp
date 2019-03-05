#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>
#include<QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, QObject::tr("Exiting"),
                                                                QObject::tr("Are you sure?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
        event->accept();
        return;
    }
    event->ignore();
}
