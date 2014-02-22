#ifndef LINEITEM_H
#define LINEITEM_H

#include <QtGui>
#include "mapview.h"

class LineItem : public QGraphicsLineItem
{
public:
    LineItem(MapView *mv){
        parent = mv;
    }

private:
    MapView *parent;
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // LINEITEM_H
