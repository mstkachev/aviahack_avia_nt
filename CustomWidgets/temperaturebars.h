#ifndef TEMPERATUREBARS_H
#define TEMPERATUREBARS_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
//using namespace QtCharts;
class TemperatureBars : public QWidget
{
    Q_OBJECT
public:
    explicit TemperatureBars(QWidget *parent = nullptr);


    QtCharts::QBarSet *low ;
    QtCharts::QBarSet *high;
    QtCharts::QStackedBarSeries *series;
    QtCharts::QChart *chart;
    QtCharts::QChartView *chartView;

signals:

};

#endif // TEMPERATUREBARS_H
