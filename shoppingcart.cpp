#include "shoppingcart.h"
#include "ui_shoppingcart.h"

shoppingCart::shoppingCart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shoppingCart)
{
    ui->setupUi(this);


    QHeaderView* header = ui->tableWidget->horizontalHeader();

    header->setSectionResizeMode((QHeaderView::Stretch));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(shop()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(close()));
}

shoppingCart::~shoppingCart()
{
    delete ui;
}

void shoppingCart::shop()
{
    Dialog buy;
    buy.setModal(true);
    buy.show();
    buy.exec();

    ui->tableWidget->setItem(0,0,buy.istad);

}
