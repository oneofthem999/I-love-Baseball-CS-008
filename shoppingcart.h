#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QDialog>
#include "dialog.h"

namespace Ui {
class shoppingCart;
}

class shoppingCart : public QDialog
{
    Q_OBJECT
public slots:
    void shop();

public:
    explicit shoppingCart(QWidget *parent = 0);
    ~shoppingCart();

private:
    Ui::shoppingCart *ui;
};

#endif // SHOPPINGCART_H
