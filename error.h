#ifndef ERROR_H
#define ERROR_H

#include <QDialog>

namespace Ui {
class error;
}

class error : public QDialog
{
    Q_OBJECT

public:
    explicit error(QWidget *parent = 0);
    ~error();
    void setError();

    QString err;

private:
    Ui::error *ui;
};

#endif // ERROR_H
