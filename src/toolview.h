#ifndef TOOLVIEW_H
#define TOOLVIEW_H
#include <QtGui>

class ToolView : public QWidget
{

    Q_OBJECT
public:
    ToolView(QWidget * parent = 0 );
    QCheckBox *correct_xy;
};

#endif // TOOLVIEW_H
