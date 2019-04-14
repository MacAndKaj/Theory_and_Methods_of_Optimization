#ifndef FUNCTIONINPUT_H
#define FUNCTIONINPUT_H

#include <QDialog>

namespace Ui {
class FunctionInput;
}

class MainWindow;

class FunctionInput : public QDialog
{
    Q_OBJECT

public:
    explicit FunctionInput(QWidget *parent = nullptr);
    ~FunctionInput();
    FunctionInput(MainWindow* _mainWindow);

public slots:
    void acceptFunction();

private:
    void createComboBox();

    Ui::FunctionInput *_ui;
    MainWindow* _mainWindow;
};



#endif // FUNCTIONINPUT_H
