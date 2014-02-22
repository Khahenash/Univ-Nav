#ifndef BATIMENTWINDOW_H
#define BATIMENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class BatimentWindow;
}

class BatimentWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit BatimentWindow(QWidget *parent = 0);
    ~BatimentWindow();
    
private:
    Ui::BatimentWindow *ui;
};

#endif // BATIMENTWINDOW_H
