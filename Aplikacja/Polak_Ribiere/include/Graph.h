#ifndef GRAPH_H
#define GRAPH_H

#include <memory>
#include <QDialog>
#include <Solver/include/Functions/FunctionWrapper.hpp>
#include <QtDataVisualization/QScatterDataProxy>
#include <QtDataVisualization/Q3DScatter>
#include <QtCharts/QtCharts>
#include <SSolution.hpp>

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

    SSolution _solution;
    std::shared_ptr<FunctionWrapper> _function;

    Ui::Graph* _ui;
    QtDataVisualization::Q3DSurface* _surface;
    QtDataVisualization::QSurfaceDataProxy* _proxyFunction;
    QtDataVisualization::QSurface3DSeries* _seriesFunction;

    QChart* _chart;

    int _min{-200};
    int _max{200};
    int _step{10};
    std::map<double, std::vector<SVector>> _3DpointsMap;
};

#endif // GRAPH_H
