#include "error.h"
#include "ui_error.h"

error::error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
}

error::~error()
{
    delete ui;
}

void error::setError()
{
    ui->label->setText(err);
}
