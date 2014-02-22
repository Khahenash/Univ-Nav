#ifndef POINTITEM_H
#define POINTITEM_H
#include <QtGui>
#include "mapview.h"

class PointItem : public QGraphicsEllipseItem
{
public:
    PointItem(MapView *mv){
        parent = mv;
    }

private:
    MapView *parent;
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // POINTITEM_H
