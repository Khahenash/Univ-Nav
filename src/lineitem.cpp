#include "lineitem.h"

void LineItem::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(!parent->mark){
        qDebug() << "line plop ! " << line().y2() << " " << this->line().y2();
        qDebug() << "line plop ! " << parent->mapFromGlobal(QCursor::pos()).ry();
        parent->link = true;
        parent->mark = true;

        parent->lastX = parent->mapFromGlobal(QCursor::pos()).rx();
        parent->lastY = parent->mapFromGlobal(QCursor::pos()).ry();




    }
}
