#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataRow>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QCustom3DItem>
#include <ui_graph.h>
#include <SSolution.hpp>
#include <Graph.h>
#include <iostream>
#include <QtDataVisualization/QCustom3DLabel>
#include <QtWidgets/QtWidgets>
#include <QtDataVisualization/QCustom3DVolume>
#include <qwt_plot.h>
#include <qwt_plot_marker.h>
#include <qwt_symbol.h>

using namespace QtDataVisualization;

Graph::Graph(const std::shared_ptr<FunctionWrapper>& function, const SSolution& solution,
    QDialog* parent)
    : QDialog(parent)
    , _solutionVector(solution.getSolutionAsMap())
    , _function(function)
    , _ui(new Ui::Graph)
    , _surface(new Q3DSurface)
{
    _ui->setupUi(this);
    _ui->radioButton_contour->setChecked(false);
    _ui->radioButton_3d->setChecked(true);
    connect(_ui->radioButton_contour, SIGNAL(clicked(bool)), this, SLOT(
                                                                       configureSolutionContourLines()));
    connect(_ui->radioButton_3d, SIGNAL(clicked(bool)), this, SLOT(configureSolutionGraph()));

    if (not _solutionVector.empty())
    {
        float minX1, maxX1, minX2, maxX2;
        minX1 = _solutionVector.begin()->first.x(1);
        maxX1 = _solutionVector.begin()->first.x(1);
        minX2 = _solutionVector.begin()->first.x(2);
        maxX2 = _solutionVector.begin()->first.x(2);

        if (minX1 < _min / _scaler) _min = minX1 * 100;
        if (minX2 < _min / _scaler) _min = minX2 * 100;
        if (maxX1 > _max / _scaler) _max = maxX1 * 100;
        if (maxX2 > _max / _scaler) _max = maxX2 * 100;
    }

    std::vector<float> x1Values, x2Values;
    for (int x = _min; x <= _max; x += _step)
    {
        x1Values.emplace_back(x / _scaler);
        x2Values.emplace_back(x / _scaler);
    }
    for (const auto& x1Value : x1Values)
    {
        for (const auto& x2Value : x2Values)
        {
            SVector wek(std::vector<double>{x1Value, x2Value});
            _3DpointsMap[*_function->operator ()(wek)].emplace_back(wek);
        }
    }
    _surface->activeTheme()->setType(Q3DTheme::ThemeRetro);
    _surface->setAxisX(new QValue3DAxis);
    _surface->setAxisY(new QValue3DAxis);
    _surface->setAxisZ(new QValue3DAxis);
    drawFunction();
    drawSolution();
    _surfaceContainer = QWidget::createWindowContainer(_surface);
    _ui->verticalLayout_2->addWidget(_surfaceContainer);
    drawFunctionContour();
    _ui->verticalLayout_2->addWidget(_chartContainer);
    _chartContainer->setVisible(false);
}

Graph::~Graph()
{
    delete _ui;
}

void Graph::configureSolutionGraph()
{
    _chartContainer->setVisible(false);
    _surfaceContainer->setVisible(true);
}

void Graph::configureSolutionContourLines()
{
    _chartContainer->setVisible(true);
    _surfaceContainer->setVisible(false);
}

void Graph::drawFunction()
{
    auto* data = new QSurfaceDataArray;
    data->reserve(abs(4 * _min * _max));
    std::vector<float> x1Values, x2Values;
    for (int x = _min; x <= _max; x += _step)
    {
        x1Values.emplace_back(x / _scaler);
        x2Values.emplace_back(x / _scaler);
    }
    for (const auto& x1Value : x1Values)
    {
        auto* row = new QSurfaceDataRow(x2Values.size());
        int index = 0;
        for (const auto& x2Value : x2Values)
        {
            SVector wek(std::vector<double>{x1Value, x2Value});
            (*row)[index++].setPosition(
                QVector3D(x2Value, *_function->operator ()(wek), x1Value));
        }
        *data << row;
    }
    _proxyFunction = new QSurfaceDataProxy();
    _proxyFunction->resetArray(data);
    _seriesFunction = new QSurface3DSeries(_proxyFunction);
    _seriesFunction->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    _seriesFunction->setFlatShadingEnabled(true);
    setUpSurface();
}

void Graph::setUpSurface()
{
    _surface->axisX()->setTitle("x1");
    _surface->axisZ()->setTitle("x2");
    _surface->axisY()->setTitle("f([x1,x2])");
    _surface->axisX()->setTitleVisible(true);
    _surface->axisY()->setTitleVisible(true);
    _surface->axisZ()->setTitleVisible(true);
    _surface->axisX()->setLabelFormat("%.2f");
    _surface->axisY()->setLabelFormat("%.2f");
    _surface->axisZ()->setLabelFormat("%.2f");
    _surface->axisX()->setLabelAutoRotation(30);
    _surface->axisY()->setLabelAutoRotation(90);
    _surface->axisZ()->setLabelAutoRotation(30);
    _surface->axisY()->setRange(_3DpointsMap.begin()->first, _3DpointsMap.rbegin()->first);
    _surface->axisX()->setRange(_min / _scaler, _max / _scaler);
    _surface->axisZ()->setRange(_min / _scaler, _max / _scaler);
    _surface->addSeries(_seriesFunction);

    QLinearGradient grOne;
    grOne.setColorAt(0.0, Qt::darkBlue);
    grOne.setColorAt(0.2, Qt::blue);
    grOne.setColorAt(0.4, Qt::darkGreen);
    grOne.setColorAt(0.6, Qt::green);
    grOne.setColorAt(0.8, Qt::darkYellow);
    grOne.setColorAt(1.0, Qt::yellow);
    _surface->seriesList().at(0)->setBaseGradient(grOne);
    _surface->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);

}

void Graph::drawSolution()
{
    QImage color = QImage(2, 2, QImage::Format_RGB666);
    color.fill(Qt::red);
    auto scale = QVector3D(0.002, 0.002, 0.002);
    int index = 1;
    for (const auto& item : _solutionVector)
    {
        auto position = QVector3D(item.first.x(2), item.second, item.first.x(1));
        for (int i = 1; i < 30; ++i)
        {
            auto* customItem = new QCustom3DItem();
            customItem->setPosition(position);
            customItem->setMeshFile("../point.obj");
            customItem->setScaling(scale);
            customItem->setTextureImage(color);
            customItem->setRotation(QQuaternion::fromAxisAndAngle(0, 1.f, 0, i * 12.f));
            _surface->addCustomItem(customItem);
        }
        auto* label = new QCustom3DLabel();
        label->setText(std::to_string(index++).c_str());
        position.setY(position.y() + 5);
        label->setPosition(position);
        label->setScaling(QVector3D(1.0f, 1.0f, 1.0f));
        _surface->addCustomItem(label);
    }
}

void Graph::drawFunctionContour()
{
    _chart = new QwtPlotSpectrogram();
    auto max = _3DpointsMap.rbegin()->first;
    auto min = _3DpointsMap.begin()->first;
    QList<double> contourLevels;
    for (double level = min;
         level < max; level += abs(max-min)/30)
    {
        contourLevels += level;
    }
    _chart->setContourLevels(contourLevels);
    auto *data = new SpectrogramData(_function);
    data->setIntervalPlot(_min/_scaler,_max/_scaler,min,max);
    _chart->setData(data);

    _chart->setDisplayMode(QwtPlotSpectrogram::ContourMode, true);
    _chart->setColorMap(new LinearColorMapRGB());

    _chart->setAlpha(255);
    auto* chartPlot = new QwtPlot();
    _chart->attach(chartPlot);

    for (const auto& item : _solutionVector)
    {
        auto* m = new QwtPlotMarker();
        m->setSymbol(new QwtSymbol(QwtSymbol::Triangle, Qt::darkMagenta, Qt::NoPen, QSize(10, 10)));
        m->setValue(item.first.x(1), item.first.x(2));
        m->attach(chartPlot);
    }
    chartPlot->replot();
    _chartContainer = chartPlot;

}