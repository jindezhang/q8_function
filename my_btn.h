#ifndef MY_BTN_H
#define MY_BTN_H

#include <QPushButton>
#include <QDebug>

class my_btn : public QPushButton
{
    Q_OBJECT
public:
    explicit my_btn(QString name,QWidget *parent = nullptr);

signals:
    void send_val(QString val);
public slots:
    void on_click();

private:

};

#endif // MY_BTN_H
