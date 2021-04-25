#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>

#include "ImageProcessing/myimagestore.h"
#include "CustomWidgets/colorscale.h"
#include "CustomWidgets/temperaturebars.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_OpenFileDialog_triggered();

private:
    Ui::MainWindow *ui;

    QLabel * _ImageViewer;
    QScrollArea *_Scroller;

    // Хранилище картинок
    MyImageStore * _ImageStore;

    //Виджеты
    ColorScale * _Scale;
    TemperatureBars *_TempBar;



};
#endif // MAINWINDOW_H
