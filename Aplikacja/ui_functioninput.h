/********************************************************************************
** Form generated from reading UI file 'functioninput.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONINPUT_H
#define UI_FUNCTIONINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FunctionInput
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_functions;
    QRadioButton *radioButton_chooseFunction;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_function;
    QRadioButton *radioButton_inputFunction;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FunctionInput)
    {
        if (FunctionInput->objectName().isEmpty())
            FunctionInput->setObjectName(QStringLiteral("FunctionInput"));
        FunctionInput->resize(724, 237);
        verticalLayout = new QVBoxLayout(FunctionInput);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox_functions = new QComboBox(FunctionInput);
        comboBox_functions->setObjectName(QStringLiteral("comboBox_functions"));

        horizontalLayout_2->addWidget(comboBox_functions);

        radioButton_chooseFunction = new QRadioButton(FunctionInput);
        radioButton_chooseFunction->setObjectName(QStringLiteral("radioButton_chooseFunction"));
        radioButton_chooseFunction->setMinimumSize(QSize(100, 0));
        radioButton_chooseFunction->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(radioButton_chooseFunction);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_function = new QLineEdit(FunctionInput);
        lineEdit_function->setObjectName(QStringLiteral("lineEdit_function"));

        horizontalLayout->addWidget(lineEdit_function);

        radioButton_inputFunction = new QRadioButton(FunctionInput);
        radioButton_inputFunction->setObjectName(QStringLiteral("radioButton_inputFunction"));
        radioButton_inputFunction->setMinimumSize(QSize(100, 0));
        radioButton_inputFunction->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(radioButton_inputFunction);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(FunctionInput);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(FunctionInput);
        QObject::connect(buttonBox, SIGNAL(rejected()), FunctionInput, SLOT(reject()));

        QMetaObject::connectSlotsByName(FunctionInput);
    } // setupUi

    void retranslateUi(QDialog *FunctionInput)
    {
        FunctionInput->setWindowTitle(QApplication::translate("FunctionInput", "Dialog", nullptr));
        radioButton_chooseFunction->setText(QApplication::translate("FunctionInput", "Choose", nullptr));
        radioButton_inputFunction->setText(QApplication::translate("FunctionInput", "Input", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FunctionInput: public Ui_FunctionInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONINPUT_H
