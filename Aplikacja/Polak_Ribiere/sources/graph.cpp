#include <include/graph.h>
#include <ui_graph.h>
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QSurfaceDataArray>
#include <QtDataVisualization/QSurfaceDataRow>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>


Graph::Graph(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::Graph)
{
    ui->setupUi(this);

    _surface = new QtDataVisualization::Q3DSurface();
    _surface->setFlags(_surface->flags() ^ Qt::FramelessWindowHint);
    QtDataVisualization::QSurfaceDataArray *data = new QtDataVisualization::QSurfaceDataArray;
    QtDataVisualization::QSurfaceDataRow *dataRow1 = new QtDataVisualization::QSurfaceDataRow;
    QtDataVisualization::QSurfaceDataRow *dataRow2 = new QtDataVisualization::QSurfaceDataRow;

    *dataRow1 << QVector3D(0.0f, 0.1f, 0.5f) << QVector3D(1.0f, 0.5f, 0.5f);
    *dataRow2 << QVector3D(0.0f, 1.8f, 1.0f) << QVector3D(1.0f, 1.2f, 1.0f);
    *data << dataRow1 << dataRow2;

    QtDataVisualization::QSurface3DSeries *series = new QtDataVisualization::QSurface3DSeries;
    series->setFlatShadingEnabled(false);
    series->dataProxy()->resetArray(data);
    _surface->addSeries(series);
    auto graphContainer = QWidget::createWindowContainer(_surface);
    ui->verticalLayout_2->addWidget(graphContainer);
}

Graph::~Graph()
{
    delete ui;
    delete _surface;
}


