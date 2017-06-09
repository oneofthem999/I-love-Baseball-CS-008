#ifndef EDITSTAD_H
#define EDITSTAD_H

#include <QDialog>

namespace Ui {
class editStad;
}

class editStad : public QDialog
{
    Q_OBJECT

public:
    explicit editStad(QWidget *parent = 0);
    ~editStad();

private:
    Ui::editStad *ui;
};

#endif // EDITSTAD_H
