#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Univ' Nav - M1 ATAL");
    w.show();
    
    return a.exec();
}
