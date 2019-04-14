#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <Solver/Logger.hpp>

class Graph;
class FunctionInput;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
    void setFunction(const std::string&);

private slots:
    inline void on_actionactionExit_triggered(){close();}
    void on_pushButton_StopShow_clicked();
    void on_pushButton_chooseFunction_clicked();

private:
    Ui::MainWindow* _ui;
    std::unique_ptr<Graph> _graph;
    std::unique_ptr<FunctionInput> _functionInput;
    Logger& _log;
//    std::unique_ptr<ISolver> _solver;
};

#endif // MAINWINDOW_H
