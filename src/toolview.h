#ifndef TOOLVIEW_H
#define TOOLVIEW_H
#include <QtGui>

class ToolView : public QWidget
{

    Q_OBJECT
public:
    ToolView(QWidget * parent = 0 );
    QPushButton *button_echelle;
    QCheckBox *correct_xy;
    QPushButton *button_escalier = new QPushButton("Escalier");
    QPushButton *button_ascenseur = new QPushButton("Ascenseur");
    QPushButton *button_porte = new QPushButton("Porte");
    QPushButton *button_qr_code = new QPushButton("QR Code");
};

#endif // TOOLVIEW_H

