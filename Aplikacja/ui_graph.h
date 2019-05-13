/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_3d;
    QRadioButton *radioButton_contour;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_close;

    void setupUi(QWidget *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName(QStringLiteral("Graph"));
        Graph->setWindowModality(Qt::WindowModal);
        Graph->resize(886, 585);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Graph->sizePolicy().hasHeightForWidth());
        Graph->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Graph);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioButton_3d = new QRadioButton(Graph);
        radioButton_3d->setObjectName(QStringLiteral("radioButton_3d"));
        radioButton_3d->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(radioButton_3d);

        radioButton_contour = new QRadioButton(Graph);
        radioButton_contour->setObjectName(QStringLiteral("radioButton_contour"));
        radioButton_contour->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(radioButton_contour);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);

        pushButton_close = new QPushButton(Graph);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

        verticalLayout->addWidget(pushButton_close);


        retranslateUi(Graph);
        QObject::connect(pushButton_close, SIGNAL(clicked()), Graph, SLOT(close()));

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QWidget *Graph)
    {
        Graph->setWindowTitle(QApplication::translate("Graph", "Graph", nullptr));
        radioButton_3d->setText(QApplication::translate("Graph", "3Dgraph", nullptr));
        radioButton_contour->setText(QApplication::translate("Graph", "Contour lines", nullptr));
        pushButton_close->setText(QApplication::translate("Graph", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
