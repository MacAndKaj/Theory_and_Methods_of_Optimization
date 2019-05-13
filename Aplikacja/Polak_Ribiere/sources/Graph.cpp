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

using namespace QtDataVisualization;

Graph::Graph(const std::shared_ptr<FunctionWrapper>& function, const SSolution& solution,
    QDialog* parent)
    : QDialog(parent)
    , _solution(solution)
    , _function(function)
    , _ui(new Ui::Graph)
    , _surface(new Q3DSurface)
    , _chart(nullptr)
{
    _ui->setupUi(this);
    _surface->activeTheme()->setType(Q3DTheme::ThemeArmyBlue);
    _surface->setAxisX(new QValue3DAxis);
    _surface->setAxisY(new QValue3DAxis);
    _surface->setAxisZ(new QValue3DAxis);
    _ui->radioButton_contour->setChecked(false);
    _ui->radioButton_3d->setChecked(true);
//    connect(_ui->radioButton_contour, SIGNAL(clicked(bool)), this, SLOT(configureSolutionContourLines()));
//    connect(_ui->radioButton_3d, SIGNAL(clicked(bool)), this, SLOT(configureSolutionGraph()));

    std::vector<float> x1Values, x2Values;
    for (int x = _min; x <= _max; x += _step)
    {
        x1Values.emplace_back(x / 100.f);
        x2Values.emplace_back(x / 100.f);
    }
    for (const auto& x1Value : x1Values)
    {
        for (const auto& x2Value : x2Values)
        {
            SVector wek(std::vector<double>{x1Value, x2Value});
            _3DpointsMap[*_function->operator ()(wek)].emplace_back(wek);
        }
    }
    auto *graphContainer = QWidget::createWindowContainer(_surface);
    drawFunction();
    drawSolution();
    _ui->verticalLayout_2->addWidget(graphContainer);
}

Graph::~Graph()
{
    delete _ui;
    delete _surface;
    delete _seriesFunction;
    delete _proxyFunction;
}

void Graph::configureSolutionGraph()
{
    if (_chart != nullptr) delete _chart;
    drawFunction();
    drawSolution();
}

void Graph::configureSolutionContourLines()
{
    if (_surface != nullptr)
    {
//        _ui->verticalLayout_2->removeWidget(_graphContainer);
        delete _surface;
        delete _seriesFunction;
        delete _proxyFunction;
    }
    drawFunctionContour();
}

void Graph::drawFunction()
{
    auto* data = new QSurfaceDataArray;
    data->reserve(abs(4*_min * _max));
    std::vector<float> x1Values, x2Values;
    for (int x = _min; x <= _max; x += _step)
    {
        x1Values.emplace_back(x / 100.f);
        x2Values.emplace_back(x / 100.f);
    }
    for (const auto& x1Value : x1Values)
    {
        auto* row = new QSurfaceDataRow(x2Values.size());
        int index = 0;
        for (const auto& x2Value : x2Values)
        {
            SVector wek(std::vector<double>{x1Value, x2Value});
            (*row)[index++].setPosition(
                QVector3D(x2Value,*_function->operator ()(wek),x1Value));
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
    _surface->axisY()->setRange(_3DpointsMap.begin()->first,_3DpointsMap.rbegin()->first);
    _surface->axisX()->setRange(_min/100.f,_max/100.f);
    _surface->axisZ()->setRange(_min/100.f,_max/100.f);
    _surface->addSeries(_seriesFunction);
}

void Graph::drawSolution()
{
    QImage color = QImage(2,2, QImage::Format_RGB666);
    color.fill(Qt::darkRed);
    auto solutionVector = _solution.getSolutionAsMap();
    for (const auto& item : solutionVector)
    {

        auto* customItem = new QCustom3DItem(
            "../point.obj",
            QVector3D(item.first.x(2), item.second, item.first.x(1)),
            QVector3D(0.5, 0.5, 0.5),
            QQuaternion::fromAxisAndAngle(1.f, 1.f, 1.f, 45.0f),
            color);
        _surface->addCustomItem(customItem);
    }
}

void Graph::drawFunctionContour()
{
    _chart = new QChart();

    auto solutionVector = _solution.getSolutionAsMap();
    std::map<double, std::vector<SVector>> contourMap;

    std::vector<std::pair<SVector, double>> functionPoints;
    for (const auto& item : functionPoints)
    {
        contourMap[item.second].push_back(item.first);
    }
    for (const auto& valueAndVectors : contourMap)
    {
        auto* series = new QLineSeries();
        for (const auto& point : valueAndVectors.second)
        {
            *series << QPointF(point.x(1), point.x(2));
        }
    }

    _ui->verticalLayout_2->addWidget(new QChartView(_chart));
}