#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Vector>

#include "login.h"
#include "editstad.h"
#include "stadiumslist.h"
#include "binarytree.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{


    Q_OBJECT
public slots:
    void logOn();
    void logOut();
    void editStadium();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



    void printList(vector<QString> items);


    int size = 0;

private:
    Ui::MainWindow *ui;
    bool admin;
    bool user;


};

#endif // MAINWINDOW_H
