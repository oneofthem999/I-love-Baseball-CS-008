#include "dialog.h"
#include "ui_dialog.h"
#include "souvenir.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{



    ui->setupUi(this);

    for (int i =0; i<stadium.names.size();++i)
   {

        ui->comboBox->addItem(stadium.names[i]);

    }


    ui->comboBox_2->addItem("Baseball Cap");
    ui->comboBox_2->addItem("Baseball Bat");
    ui->comboBox_2->addItem("Stadium Pennant");
    ui->comboBox_2->addItem("Autograph Baseball");

    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(bought()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));



}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::bought()
{

    istad = stadium.names[ui->comboBox->currentIndex()];


}
