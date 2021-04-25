#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),_Scale(new ColorScale(this)),_TempBar(new TemperatureBars(this))
{






//_ImageViewer->showFullScreen();
  ui->setupUi(this);
_ImageViewer =  new QLabel(this);

ui->horizontalLayout->addWidget(_ImageViewer,Qt::AlignLeft);
ui->horizontalLayout->addWidget(_Scale,Qt::AlignRight);
//ui->verticalLayout->addWidget(_TempBar);
//ui->LayutColour->addWidget(_Scale,Qt::AlignRight);
 _ImageViewer->setBackgroundRole(QPalette::Base);
  _ImageViewer->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
//  _ImageViewer->setAlignment(Qt::AlignBottom | Qt::AlignRight);
  _ImageViewer->setScaledContents(true);
_Scale->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
_Scale->setMaximumWidth(50);

  // _Scroller->setBackgroundRole(QPalette::Dark);
  // _Scroller->setWidget(_ImageViewer);
  // _Scroller->setVisible(false);
  // ui->horizontalLayout->addWidget(_Scroller,Qt::AlignBottom);
  // setCentralWidget(_Scroller);

//resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);

    _ImageStore =  new MyImageStore(this,_ImageViewer);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenFileDialog_triggered()
{
 _ImageStore->AddImagefromFileDialog();
}
