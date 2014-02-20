#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Univ' Nav - M1 ATAL");
    w.showMaximized();
    
    return a.exec();
}
