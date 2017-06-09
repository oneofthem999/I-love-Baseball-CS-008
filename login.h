#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <error.h>

namespace Ui {
class logIn;
}

class logIn : public QDialog
{
    Q_OBJECT
public slots:
    void logging();
public:
    explicit logIn(QWidget *parent = 0);
    ~logIn();

    bool user = false;
    bool admin = false;

private:
    Ui::logIn *ui;
};

#endif // LOGIN_H
