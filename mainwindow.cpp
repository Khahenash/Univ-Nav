#include "mainwindow.h"
#include "mapview.h"
#include <QLabel>
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsPixmapItem *mapItem = new QGraphicsPixmapItem(0,scene);
    QPixmap mapImage;
    mapImage.load("plan.jpg");
    mapItem->setPixmap(mapImage);


    QGraphicsEllipseItem *markItem2 = new QGraphicsEllipseItem(100, 50, 18, 18);
    markItem2->setBrush(QColor(0,52,102));
    markItem2->setPen(Qt::NoPen);
    scene->addItem(markItem2);

    QGraphicsEllipseItem *markItem3 = new QGraphicsEllipseItem(96, 46, 26, 26);
    //markItem3->setBrush(Qt::blue);
    QPen p = markItem3->pen();
    p.setColor(QColor(0,52,102));
    p.setWidth(3);
    markItem3->setPen(p);
    scene->addItem(markItem3);


    QGraphicsView *view = new MapView();
    view->setScene(scene);
    view->setParent(this);
    view->setMinimumWidth(mapImage.width()+5);
    view->setMinimumHeight(mapImage.height()+5);
    view->setMaximumWidth(mapImage.width()+5);
    view->setMaximumHeight(mapImage.height()+5);
    this->setMinimumHeight(view->height());
    this->setMinimumWidth(view->width());
}

MainWindow::~MainWindow()
{

}

