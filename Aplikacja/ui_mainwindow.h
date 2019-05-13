/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionactionExit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBox_methods;
    QPushButton *pushButton_chooseFunction;
    QLabel *label_chosenFunction;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_ValueError;
    QLabel *label_gradientError;
    QLineEdit *lineEdit_gradientError;
    QLabel *label_valDiffError;
    QLineEdit *lineEdit_StepError;
    QLabel *label_stepsError;
    QDoubleSpinBox *doubleSpinBox_armijo;
    QLabel *label_armijoError;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar_computing;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_numberOfIterations;
    QSpinBox *spinBox_iterations;
    QPushButton *pushButton_start;
    QPushButton *pushButton_show;
    QPushButton *pushButton_quit;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_View;
    QMenu *menu_Edit;
    QMenu *menu_Help;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(882, 596);
        actionactionExit = new QAction(MainWindow);
        actionactionExit->setObjectName(QStringLiteral("actionactionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        comboBox_methods = new QComboBox(centralWidget);
        comboBox_methods->setObjectName(QStringLiteral("comboBox_methods"));

        verticalLayout_3->addWidget(comboBox_methods);

        pushButton_chooseFunction = new QPushButton(centralWidget);
        pushButton_chooseFunction->setObjectName(QStringLiteral("pushButton_chooseFunction"));

        verticalLayout_3->addWidget(pushButton_chooseFunction);

        label_chosenFunction = new QLabel(centralWidget);
        label_chosenFunction->setObjectName(QStringLiteral("label_chosenFunction"));
        label_chosenFunction->setFrameShape(QFrame::Box);
        label_chosenFunction->setFrameShadow(QFrame::Raised);
        label_chosenFunction->setLineWidth(4);
        label_chosenFunction->setAlignment(Qt::AlignCenter);
        label_chosenFunction->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_3->addWidget(label_chosenFunction);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout->setHorizontalSpacing(2);
        formLayout->setVerticalSpacing(4);
        lineEdit_ValueError = new QLineEdit(centralWidget);
        lineEdit_ValueError->setObjectName(QStringLiteral("lineEdit_ValueError"));
        lineEdit_ValueError->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit_ValueError);

        label_gradientError = new QLabel(centralWidget);
        label_gradientError->setObjectName(QStringLiteral("label_gradientError"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_gradientError);

        lineEdit_gradientError = new QLineEdit(centralWidget);
        lineEdit_gradientError->setObjectName(QStringLiteral("lineEdit_gradientError"));
        lineEdit_gradientError->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEdit_gradientError);

        label_valDiffError = new QLabel(centralWidget);
        label_valDiffError->setObjectName(QStringLiteral("label_valDiffError"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_valDiffError);

        lineEdit_StepError = new QLineEdit(centralWidget);
        lineEdit_StepError->setObjectName(QStringLiteral("lineEdit_StepError"));
        lineEdit_StepError->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEdit_StepError);

        label_stepsError = new QLabel(centralWidget);
        label_stepsError->setObjectName(QStringLiteral("label_stepsError"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_stepsError);

        doubleSpinBox_armijo = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_armijo->setObjectName(QStringLiteral("doubleSpinBox_armijo"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox_armijo->sizePolicy().hasHeightForWidth());
        doubleSpinBox_armijo->setSizePolicy(sizePolicy);
        doubleSpinBox_armijo->setMaximumSize(QSize(100, 16777215));
        doubleSpinBox_armijo->setDecimals(6);
        doubleSpinBox_armijo->setMinimum(1e-06);
        doubleSpinBox_armijo->setMaximum(0.9);
        doubleSpinBox_armijo->setSingleStep(1e-06);
        doubleSpinBox_armijo->setValue(1e-06);

        formLayout->setWidget(3, QFormLayout::LabelRole, doubleSpinBox_armijo);

        label_armijoError = new QLabel(centralWidget);
        label_armijoError->setObjectName(QStringLiteral("label_armijoError"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_armijoError);


        horizontalLayout_3->addLayout(formLayout);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout_3->addWidget(textBrowser);


        verticalLayout_3->addLayout(horizontalLayout_3);

        progressBar_computing = new QProgressBar(centralWidget);
        progressBar_computing->setObjectName(QStringLiteral("progressBar_computing"));
        progressBar_computing->setValue(24);

        verticalLayout_3->addWidget(progressBar_computing);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_numberOfIterations = new QLabel(centralWidget);
        label_numberOfIterations->setObjectName(QStringLiteral("label_numberOfIterations"));
        label_numberOfIterations->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_numberOfIterations);


        horizontalLayout_2->addLayout(horizontalLayout_4);

        spinBox_iterations = new QSpinBox(centralWidget);
        spinBox_iterations->setObjectName(QStringLiteral("spinBox_iterations"));
        spinBox_iterations->setMaximum(99999);

        horizontalLayout_2->addWidget(spinBox_iterations);

        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));

        horizontalLayout_2->addWidget(pushButton_start);

        pushButton_show = new QPushButton(centralWidget);
        pushButton_show->setObjectName(QStringLiteral("pushButton_show"));
        pushButton_show->setEnabled(true);

        horizontalLayout_2->addWidget(pushButton_show);

        pushButton_quit = new QPushButton(centralWidget);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));

        horizontalLayout_2->addWidget(pushButton_quit);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 882, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(actionactionExit);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_quit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionactionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_chooseFunction->setText(QApplication::translate("MainWindow", "Choose a function", nullptr));
        label_chosenFunction->setText(QString());
        lineEdit_ValueError->setText(QApplication::translate("MainWindow", "1e-5", nullptr));
        label_gradientError->setText(QApplication::translate("MainWindow", "Gradient error", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_gradientError->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Gradient error</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_gradientError->setText(QApplication::translate("MainWindow", "1e-5", nullptr));
        label_valDiffError->setText(QApplication::translate("MainWindow", "Values difference error", nullptr));
        lineEdit_StepError->setText(QApplication::translate("MainWindow", "1e-5", nullptr));
        label_stepsError->setText(QApplication::translate("MainWindow", "Steps error", nullptr));
        label_armijoError->setText(QApplication::translate("MainWindow", "Minimalization in direction parameter", nullptr));
        label_numberOfIterations->setText(QApplication::translate("MainWindow", "Number of Iterations", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        pushButton_show->setText(QApplication::translate("MainWindow", "Show Graphical Solution", nullptr));
        pushButton_quit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        menu_File->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menu_View->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menu_Help->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
