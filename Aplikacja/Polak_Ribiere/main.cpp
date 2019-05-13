#include <MainWindow.h>
#include <QApplication>
#include <exception>

int main(int argc, char* argv[])
{
    int returnedValue = 0;
    try
    {
        Logger& log = LoggersFactory::getLoggersFactory().getLogger("Application");
        log << "I[[START]]";
        QApplication a(argc, argv);
        a.setAttribute(Qt::AA_UseSoftwareOpenGL);
        QIcon icon(":/opt.png");
        MainWindow w;

        w.setWindowIcon(icon);
        w.setWindowTitle(QObject::tr("Polak-Ribiere"));
        w.show();

        returnedValue = QApplication::exec();
        log << "I[[STOP]]"  " Returned value is " + std::to_string(returnedValue);
    }
    catch (const std::exception& except)
    {
        std::cerr << except.what() << std::endl;
    }

    return returnedValue;
}
