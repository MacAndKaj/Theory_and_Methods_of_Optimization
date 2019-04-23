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
    ~FunctionInput() override;
    explicit FunctionInput(MainWindow* _mainWindow);
    const std::string& getChosenFunction() const;

public slots:
    void acceptFunction();
    void radioButtonChanged();

private:
    void setUp();
    void createComboBox();

    Ui::FunctionInput *_ui;
    MainWindow* _mainWindow;
    std::string _chosenFunction;
};



#endif // FUNCTIONINPUT_H
