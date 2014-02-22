#include "mainwindow.h"
#include "firstwindow.h"
#include "batimentwindow.h"
#include "etagewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   EtageWindow w;
   // BatimentWindow w;
   //   FirstWindow w;
   // MainWindow w;
    w.setWindowTitle("Univ' Nav - M1 ATAL");
    w.showMaximized();
    
    return a.exec();
}
