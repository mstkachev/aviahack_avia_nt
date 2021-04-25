#ifndef COLORSCALE_H
#define COLORSCALE_H

#include <QWidget>
#include <QPainter>

class ColorScale : public QWidget
{
    Q_OBJECT
public:
    explicit ColorScale(QWidget *parent = nullptr);

     using QWidget::QWidget;
protected:
    void paintEvent(QPaintEvent *event) override {
            QPainter painter(this);
            painter.setOpacity(0.7);
            painter.setRenderHint(QPainter::HighQualityAntialiasing);
            QLinearGradient gradient(0, 0, 0, height());
            QGradientStops stops;
            stops << QGradientStop(0, Qt::red);
            stops << QGradientStop(1.0/3, Qt::blue);
            stops << QGradientStop(2.0/3, Qt::green);
            stops << QGradientStop(1, Qt::red);

            gradient.setStops(stops);

            painter.fillRect(rect(), gradient);
            auto _rect  = rect();
            int temperature = 23;
             size_t sizeperchoise = 50;
            for (int var = 0; var < 5; ++var) {


                _rect.adjust(0,sizeperchoise,0,0);

                painter.drawText(_rect,QString("%1 °C").arg(temperature));
                 temperature -=10;
                 sizeperchoise +=50;
            }


    }
signals:

};

#endif // COLORSCALE_H
