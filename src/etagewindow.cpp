#include "etagewindow.h"
#include "ui_etagewindow.h"

EtageWindow::EtageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EtageWindow)
{
    ui->setupUi(this);
}

EtageWindow::~EtageWindow()
{
    delete ui;
}
