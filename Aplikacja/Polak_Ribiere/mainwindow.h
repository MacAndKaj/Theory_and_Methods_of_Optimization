#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"
#include <memory>
#include <QMainWindow>


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

private slots:
    inline void on_actionactionExit_triggered(){close();}

    void on_pushButton_StopShow_clicked();
    unsigned int getNumberOfIterations() const;

private:
    Ui::MainWindow* _ui;
    std::unique_ptr<Graph> _graph;
};

#endif // MAINWINDOW_H
