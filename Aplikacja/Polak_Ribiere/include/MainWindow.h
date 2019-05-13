#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <Logger/LoggersFactory.hpp>
#include <Definitions_and_Helpers/Definitions.hpp>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidgetItem>
#include "SolverWrapper.h"
#include <ui_mainwindow.h>

class Graph;
class FunctionInput;


namespace
{
    std::vector<std::pair<QString, MethodType>> methodsVector = {
        std::pair<QString, MethodType>{"Unknown", MethodType::MethodType_Unknown}
        , std::pair<QString, MethodType>{"Polak-Ribiere"
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

public slots:
    void setFunction();
    void currentMethodChanged(int);
    void iterationDone(const FunctionInPointParameters&);

private slots:

    inline void on_actionactionExit_triggered()
    { close();}

    void on_pushButton_show_clicked();
    void on_pushButton_chooseFunction_clicked();
    void startClicked();

private:
    void startComputing();
    void setupComboBox();
    void startingPointEdit(unsigned int);

    Ui::MainWindow* _ui;
    Graph* _graph;
    FunctionInput* _functionInput;
    SolverWrapper _solver;
    Logger& _log;

    std::vector<QLabel*> _labels;
    std::vector<QLineEdit*> _lineEdits;
    std::vector<QFormLayout*> _layouts;
};

#endif // MAINWINDOW_H
