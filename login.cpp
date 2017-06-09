#include "login.h"
#include "ui_login.h"

logIn::logIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logIn)
{
    ui->setupUi(this);

    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(logging()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
}

logIn::~logIn()
{
    delete ui;
}

void logIn::logging()
{
    bool again = true;
    QString temp;

    temp = ui->textEdit->toPlainText();
    if(temp == "user")
    {
        user = true;
        again = false;
        close();
    }

    else if(temp == "admin")
    {
        admin = true;
        again = false;
        close();
    }
    if(user == false && admin == false)
    {
        error err;
        err.err ="The Username \""+temp+"\" does not exist";
        err.setError();
        err.show();
        err.setModal(true);
        err.exec();

        again = true;


    }





}
