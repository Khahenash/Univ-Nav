#ifndef MAPVIEW_H
#define MAPVIEW_H
#include <QtGui>

class MapView : public QGraphicsView
{

    Q_OBJECT
public:
    MapView(QWidget * parent = 0 );
    int lastX ;
    int lastY;
    bool link;
    int correctX;
    int correctY;
    bool correct; // correction d'angle des liaisons
    bool mark ; // ajout d'intersections
    bool access ;
    bool echelle1 ;
    bool echelle2 ;
    int echellel ;
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
