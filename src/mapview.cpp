#include "mapview.h"
#include "pointitem.h"
#include "lineitem.h"

MapView::MapView(){
    setMouseTracking(true);
}


void MapView::mousePressEvent(QMouseEvent *event){
    QGraphicsView::mousePressEvent(event);

    if(echelle1){
        echelle1 = false;
        echelle2 = true;

        QGraphicsEllipseItem *p = new QGraphicsEllipseItem();
        p->setRect(mapFromGlobal(QCursor::pos()).rx()-5, mapFromGlobal(QCursor::pos()).ry()-5, 10, 10);
        p->setBrush(QColor(0,52,102));
        p->setPen(Qt::NoPen);
        p->setZValue(1);
        scene()->addItem(p);

        lastX = mapFromGlobal(QCursor::pos()).rx()-5;
        lastY = mapFromGlobal(QCursor::pos()).ry()-5;
    }
    else if(echelle2){
        echelle2 = false;

        QGraphicsEllipseItem *p = new QGraphicsEllipseItem();
        p->setRect(mapFromGlobal(QCursor::pos()).rx()-5, mapFromGlobal(QCursor::pos()).ry()-5, 10, 10);
        p->setBrush(QColor(0,52,102));
        p->setPen(Qt::NoPen);
        p->setZValue(1);
        scene()->addItem(p);

        echellel = sqrt((lastX-mapFromGlobal(QCursor::pos()).rx()-5)*(lastX-mapFromGlobal(QCursor::pos()).rx()-5) + (lastY-mapFromGlobal(QCursor::pos()).ry()-5)*(lastY-mapFromGlobal(QCursor::pos()).ry()-5));
    }

    if(mark){
        lastX = mapFromGlobal(QCursor::pos()).rx();
        lastY = mapFromGlobal(QCursor::pos()).ry();

        if(link){
            lastX = correctX;
            lastY = correctY;
        }

        if(access){

            QGraphicsEllipseItem *markItem = new QGraphicsEllipseItem(lastX-13, lastY-13, 26, 26);
            QPen pen = markItem->pen();
            pen.setColor(QColor(0,52,102));
            pen.setWidth(3);
            markItem->setPen(pen);
            scene()->addItem(markItem);

            PointItem *p = new PointItem(this);
            p->setRect(lastX-9, lastY-9, 18, 18);
            p->setBrush(QColor(0,52,102));
            p->setPen(Qt::NoPen);
            p->setZValue(1);
            scene()->addItem(p);
        }
        else{
            PointItem *p = new PointItem(this);
            p->setRect(lastX-10, lastY-10, 20, 20);
            p->setBrush(QColor(0,52,102));
            p->setPen(Qt::NoPen);
            p->setZValue(1);
            scene()->addItem(p);
            this->link = true;
        }
        lastLine = NULL;
    }
}

void MapView::mouseMoveEvent(QMouseEvent *event){
    QGraphicsView::mouseMoveEvent(event);


    this->correctX = mapFromGlobal(QCursor::pos()).rx();
    this->correctY = mapFromGlobal(QCursor::pos()).ry();

    if(this->link){
        this->mark=true;
        if(this->correct){
            double pi = 3.14159265;
            if( (mapFromGlobal(QCursor::pos()).rx()-lastX)!=0 ){
                double angle = atan2((lastY-correctY),(correctX-lastX))*180/pi;
                if ((angle>-22.5 && angle<=22.5) || ( angle>157.5 || angle<=-157.5)){
                    correctY = this->lastY;
                }
                else if((angle>67.5 && angle<=112.5) || (angle<-67.5 && angle>=-112.5)){
                    correctX = this->lastX;
                }
            }
        }

        if(lastLine!=NULL){
            scene()->removeItem(lastLine);
        }

        //QGraphicsLineItem *line = new QGraphicsLineItem(this->lastX, this->lastY, correctX, correctY);
        LineItem *line = new LineItem(this);
        line->setLine(this->lastX, this->lastY, correctX, correctY);
        QPen p = line->pen();
        p.setColor(QColor(0,52,102));
        p.setWidth(8);
        line->setPen(p);
        scene()->addItem(line);
        lastLine = line;


    }

    if(lastMark!=NULL){
        scene()->removeItem(lastMark);
    }
    if(mark){
        QGraphicsEllipseItem *markItem = new QGraphicsEllipseItem(correctX-10, correctY-10, 20, 20);
        markItem->setBrush(QColor(0,52,102));
        markItem->setPen(Qt::NoPen);
        scene()->addItem(markItem);
        lastMark = markItem;
    }
}

void MapView::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Escape:
            this->link = false;
            this->mark = false;
            this->access = false;
            if(lastMark!=NULL){
                scene()->removeItem(lastMark);
                lastMark = NULL;
            }
            if(lastLine!=NULL){
                scene()->removeItem(lastLine);
                lastLine = NULL;
            }
            this->echelle1 = false;
            this->echelle2 = false;
            break;
        case Qt::Key_F4:
            this->access = true;
            this->mark = true;
            break;
        case Qt::Key_F3:
            this->mark = true;
            break;
        case Qt::Key_F2:
            this->correct = !this->correct;
            break;
        case Qt::Key_F1:
            this->echelle1 = true;
            break;
    }
}

void MapView::accessmode(){
    this->access = true;
    this->mark = true;
}

void MapView::echellemode(){
    this->echelle1 = true;
}

void MapView::couloirmode(){

}

void MapView::echapmode(){
    this->link = false;
    this->mark = false;
    this->access = false;
    if(lastMark!=NULL){
        scene()->removeItem(lastMark);
        lastMark = NULL;
    }
    if(lastLine!=NULL){
        scene()->removeItem(lastLine);
        lastLine = NULL;
    }
    this->echelle1 = false;
    this->echelle2 = false;

}

void MapView::correctmode(){
    this->correct = !this->correct;
}
