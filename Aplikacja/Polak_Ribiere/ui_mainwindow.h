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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionactionExit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_chooseFunction;
    QWidget *widget_startParameters;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar_computing;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_numberOfIterations;
    QSpinBox *spinBox_iterations;
    QCheckBox *checkBox;
    QPushButton *pushButton_start;
    QPushButton *pushButton_StopShow;
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
        pushButton_chooseFunction = new QPushButton(centralWidget);
        pushButton_chooseFunction->setObjectName(QStringLiteral("pushButton_chooseFunction"));

        verticalLayout_3->addWidget(pushButton_chooseFunction);

        widget_startParameters = new QWidget(centralWidget);
        widget_startParameters->setObjectName(QStringLiteral("widget_startParameters"));

        verticalLayout_3->addWidget(widget_startParameters);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

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

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(false);
        checkBox->setTristate(false);

        horizontalLayout_2->addWidget(checkBox);

        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));

        horizontalLayout_2->addWidget(pushButton_start);

        pushButton_StopShow = new QPushButton(centralWidget);
        pushButton_StopShow->setObjectName(QStringLiteral("pushButton_StopShow"));

        horizontalLayout_2->addWidget(pushButton_StopShow);

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
        label_numberOfIterations->setText(QApplication::translate("MainWindow", "Number of Iterations", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Visualisation", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        pushButton_StopShow->setText(QApplication::translate("MainWindow", "Stop", nullptr));
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
