#include "batimentwindow.h"
#include "ui_batimentwindow.h"

BatimentWindow::BatimentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BatimentWindow)
{
    ui->setupUi(this);
}

BatimentWindow::~BatimentWindow()
{
    delete ui;
}
