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
    QGraphicsLineItem *lastLine = NULL;
    QGraphicsEllipseItem *lastMark = NULL;
private:
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAPVIEW_H
