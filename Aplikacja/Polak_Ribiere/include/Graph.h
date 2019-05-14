#ifndef GRAPH_H
#define GRAPH_H

#include <memory>
#include <QDialog>
#include <Solver/include/Functions/FunctionWrapper.hpp>
#include <QtDataVisualization/QScatterDataProxy>
#include <QtDataVisualization/Q3DScatter>
#include <QtCharts/QtCharts>
#include <SSolution.hpp>
#include <qwt_plot_spectrogram.h>
#include <qwt_color_map.h>

namespace Ui
{
    class Graph;
}

namespace QtDataVisualization
{
    class Q3DSurface;
    class QSurface3DSeries;
    class QSurfaceDataProxy;
}

class SSolution;

class Graph : public QDialog
{
Q_OBJECT
public:
    Graph(const std::shared_ptr<FunctionWrapper>& function, const SSolution&,
        QDialog* parent = nullptr);
    ~Graph();
public slots:
    void configureSolutionGraph();
    void configureSolutionContourLines();

private slots:

    inline void on_pushButton_close_clicked()
    { close(); }

private:
    void drawFunction();
    void drawSolution();
    void setUpSurface();

    void drawFunctionContour();

    std::vector<std::pair<SVector, double>> _solutionVector;
    std::shared_ptr<FunctionWrapper> _function;

    Ui::Graph* _ui;
    QWidget* _surfaceContainer;
    QWidget* _chartContainer;
    QtDataVisualization::Q3DSurface* _surface;
    QtDataVisualization::QSurfaceDataProxy* _proxyFunction;
    QtDataVisualization::QSurface3DSeries* _seriesFunction;
    QwtPlotSpectrogram* _chart;

    int _min{-200};
    int _max{200};
    int _step{1};
    float _scaler{100.f};
    std::map<double, std::vector<SVector>> _3DpointsMap;
};

class SpectrogramData: public QwtRasterData
{
public:
    explicit SpectrogramData(const std::shared_ptr<FunctionWrapper>& function)
        : _function(function)
    {
    }
    void setIntervalPlot(double min,double max,
        double minVal,double maxVal)
    {
        setInterval( Qt::XAxis, QwtInterval( min,max) );
        setInterval( Qt::YAxis, QwtInterval( min, max ) );
        setInterval( Qt::ZAxis, QwtInterval( minVal, maxVal ) );
    }

    double value( double x, double y ) const override
    {
        auto vec = {x,y};
        return *_function->operator()(SVector(vec));
    }
    std::shared_ptr<FunctionWrapper> _function;
};

class LinearColorMapRGB: public QwtLinearColorMap
{
public:
    LinearColorMapRGB():
        QwtLinearColorMap( Qt::darkBlue, Qt::red, QwtColorMap::RGB )
    {
        addColorStop( 0.1, Qt::blue );
        addColorStop( 0.3, Qt::darkGreen );
        addColorStop( 0.4, Qt::green );
        addColorStop( 0.5, Qt::darkYellow );
        addColorStop( 0.7, Qt::yellow );
        addColorStop( 0.9, Qt::darkRed);
    }
};

#endif // GRAPH_H
