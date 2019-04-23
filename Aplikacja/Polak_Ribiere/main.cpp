#include <MainWindow.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    Logger& log = LoggersFactory::getLoggersFactory().getLogger("Application");
    log << "[[START]]";
    QApplication a(argc, argv);
    QIcon icon(":/opt.png");
    MainWindow w;

    w.setWindowIcon(icon);
    w.setWindowTitle(QObject::tr("Polak-Ribiere"));
    w.show();

    auto returnedValue = QApplication::exec();
    log << "[[STOP]]"  " Returned value is " + std::to_string(returnedValue);
    return returnedValue;
}
