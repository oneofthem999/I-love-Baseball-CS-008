#include "editstad.h"
#include "ui_editstad.h"

editStad::editStad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editStad)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));
}

editStad::~editStad()
{
    delete ui;
}
