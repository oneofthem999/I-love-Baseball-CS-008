#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qlist>

StadiumsList stadiums;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QList<QString> labels;



    labels.push_back("Stadium");
    labels.push_back("Location");
    labels.push_back("Occupancy");
    labels.push_back("Date");

    //printList(stadiums.names);

    //for int


    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->hide();
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_4->hide();

    QHeaderView* header = ui->tableWidget->horizontalHeader();

    header->setSectionResizeMode((QHeaderView::Stretch));
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setRowCount(stadiums.names.size());


    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(logOn()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(logOut()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(editStadium()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(shop()));

    printList(stadiums.names);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::logOn()
{
    logIn log;

    log.show();
    log.setModal(true);
    log.exec();

    if(log.user == true)
    {
        user = true;

        ui->pushButton->hide();
        ui->pushButton->setEnabled(false);
        ui->pushButton_4->show();
        ui->pushButton_4->setEnabled(true);
    }
    else if(log.admin == true)
    {
        admin = true;
        ui->pushButton->hide();
        ui->pushButton->setEnabled(false);
        ui->pushButton_4->show();
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_2->show();
        ui->pushButton_2->setEnabled(true);
    }

}

void MainWindow::logOut()
{
    admin = true;
    user = true;

    ui->pushButton->show();
    ui->pushButton->setEnabled(true);

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->hide();
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_4->hide();


}

void MainWindow::editStadium()
{
    editStad edit;

    edit.setModal(true);
    edit.show();
    edit.exec();
}


void MainWindow::printList(vector<QString> items)
{

    for(int i = 0; i < stadiums.names.size();++i)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(items[i]));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(stadiums.address[i]));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(stadiums.cap[i]));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(stadiums.dates[i]));

    }
}

void MainWindow::shop()
{
    cart.setModal(true);
    cart.show();
    cart.exec();
}

