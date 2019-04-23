#ifndef GRAPH_H
#define GRAPH_H

#include <memory>
#include <QDialog>

namespace Ui {
    class Graph;
}

namespace QtDataVisualization {
    class Q3DSurface;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QDialog *parent = nullptr);
    ~Graph();

private slots:
    inline void on_pushButton_close_clicked(){close();}

private:
    Ui::Graph *ui;
    QtDataVisualization::Q3DSurface* _surface;
};

#endif // GRAPH_H
