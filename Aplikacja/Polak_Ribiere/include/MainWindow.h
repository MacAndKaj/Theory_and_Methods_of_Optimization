#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>

#include <Logger/LoggersFactory.hpp>
#include <Definitions_and_Helpers/Definitions.hpp>
#include "SolverWrapper.h"

class Graph;
class FunctionInput;


namespace Ui
{
    class MainWindow;
}

namespace
{
    std::vector<std::pair<QString, MethodType>> methodsMap = {
        std::pair<QString, MethodType>{"MethodType_Unknown", MethodType::MethodType_Unknown}
        , std::pair<QString, MethodType>{"MethodType_PolakRibiere"
                                         , MethodType::MethodType_PolakRibiere}
    };
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;
    void closeEvent(QCloseEvent* event) override;
    void setFunction(const std::string&);

public slots:
    void currentMethodChanged(int);

private slots:

    inline void on_actionactionExit_triggered()
    { close(); }

    void on_pushButton_StopShow_clicked();
    void on_pushButton_chooseFunction_clicked();
    void startClicked();

private:
    void startComputing();
    void setupComboBox();

    Ui::MainWindow* _ui;
    std::unique_ptr<Graph> _graph;
    std::unique_ptr<FunctionInput> _functionInput;
    SolverWrapper _solver;
    Logger& _log;
};

#endif // MAINWINDOW_H
