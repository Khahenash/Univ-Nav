#include "mainwindow.h"
#include "mapview.h"
#include "toolview.h"
#include <QLabel>
#include <QColor>

#include <QFileDialog>
#include <QGridLayout>
#include <QSplitter>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    this->setCentralWidget(new QWidget(this));
    QGridLayout *centralLayout = new QGridLayout(centralWidget());
    QSplitter *splitter = new QSplitter(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsPixmapItem *mapItem = new QGraphicsPixmapItem(0, scene);
    QPixmap mapImage;
    mapImage.load("plan.jpg");
    mapItem->setPixmap(mapImage);

    MapView *view = new MapView();
    view->setScene(scene);
    view->setMinimumWidth(mapImage.width()+5);
    view->setMinimumHeight(mapImage.height()+5);
    view->setMaximumWidth(mapImage.width()+5);
    view->setMaximumHeight(mapImage.height()+5);
    splitter->addWidget(view);

    ToolView *tv = new ToolView();
    tv->setParent(this);
    splitter->addWidget(tv);
    tv->setMaximumWidth(500);
    this->setStyleSheet("QMainWindow{background-color:white;}");

    view->setParent(splitter);


   connect(tv->correct_xy,SIGNAL(clicked()), view,SLOT(correctmode()));
   connect(tv->button_echelle,SIGNAL(clicked()), view,SLOT(echellemode()));

   connect(tv->button_ascenseur,SIGNAL(clicked()), view,SLOT(accessmode()));
   connect(tv->button_escalier,SIGNAL(clicked()), view,SLOT(accessmode()));
   connect(tv->button_porte,SIGNAL(clicked()), view,SLOT(accessmode()));
   connect(tv->button_qr_code,SIGNAL(clicked()), view,SLOT(accessmode()));

    centralLayout->addWidget(splitter, 0, 0, 1, -1);

    this->setMinimumHeight(view->height());
    this->setMinimumWidth(view->width());
}

MainWindow::~MainWindow()
{

}


