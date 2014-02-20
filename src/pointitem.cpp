#include "pointitem.h"

void PointItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug() << "plop ! " << this->rect().x() << " : " << this->rect().y();
    if(this->parent->link){
        this->parent->scene()->removeItem(this->parent->lastLine);
        this->parent->scene()->removeItem(this->parent->lastMark);
        QGraphicsLineItem *line = new QGraphicsLineItem(this->parent->lastX, this->parent->lastY, rect().x()+10, rect().y()+10);
        QPen p = line->pen();
        p.setColor(QColor(0,52,102));
        p.setWidth(8);
        line->setPen(p);
        this->parent->scene()->addItem(line);
        this->parent->mark = false;
        this->parent->lastX = rect().x()+10;
        this->parent->lastY = rect().y()+10;
    }
    else{
        this->parent->lastX = this->rect().x()+10;
        this->parent->lastY = this->rect().y()+10;
        this->parent->link = true;
        this->parent->mark = false;
    }
}
