#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <stadiumslist.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public slots:
    void bought();


public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QString istad;
    QString items;
    StadiumsList stadium;
    Souvenir stuff;
    int amount;

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
