#ifndef ETAGEWINDOW_H
#define ETAGEWINDOW_H

#include <QMainWindow>

namespace Ui {
class EtageWindow;
}

class EtageWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit EtageWindow(QWidget *parent = 0);
    ~EtageWindow();
    
private:
    Ui::EtageWindow *ui;
};

#endif // ETAGEWINDOW_H
