#include "mapview.h"
#include "pointitem.h"
#include "lineitem.h"

MapView::MapView(){
    setMouseTracking(true);
}

void MapView::mousePressEvent(QMouseEvent *event){
    QGraphicsView::mousePressEvent(event);

    if(mark){
        lastX = mapFromGlobal(QCursor::pos()).rx();
        lastY = mapFromGlobal(QCursor::pos()).ry();

        if(link){
            lastX = correctX;
            lastY = correctY;
        }


        PointItem *p = new PointItem(this);
        p->setRect(lastX-10, lastY-10, 20, 20);
        p->setBrush(QColor(0,52,102));
        p->setPen(Qt::NoPen);
        scene()->addItem(p);

        this->link = true;
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
            if(lastMark!=NULL){
                scene()->removeItem(lastMark);
                lastMark = NULL;
            }
            if(lastLine!=NULL){
                scene()->removeItem(lastLine);
                lastLine = NULL;
            }
            break;
        case Qt::Key_F3:
            this->mark = true;
            break;
        case Qt::Key_F2:
            this->correct = !this->correct;
            break;
    }
}
