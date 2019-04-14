#include "include/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon icon(":/opt.png");
    MainWindow w;

    w.setWindowIcon(icon);
    w.setWindowTitle(QObject::tr("Polak-Ribiere"));
    w.show();

    return a.exec();
}
