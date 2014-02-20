#ifndef MAPVIEW_H
#define MAPVIEW_H
#include <QtGui>

class MapView : public QGraphicsView
{
public:
    MapView();
    int lastX = 0;
    int lastY = 0;
    bool link = false;
    int correctX;
    int correctY;
    bool correct = true; // correction d'angle des liaisons
    bool mark = false; // ajout d'intersections
    bool access = false;
    bool echelle1 = false;
    bool echelle2 = false;
    int echellel = 0;
    QGraphicsLineItem *lastLine = NULL;
    QGraphicsEllipseItem *lastMark = NULL;
private:
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void echellemode();
    void accessmode();
    void couloirmode();
    void echapmode();
    void correctmode();
};

#endif // MAPVIEW_H
