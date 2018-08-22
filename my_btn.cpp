#include "my_btn.h"

my_btn::my_btn(QWidget *parent) : QPushButton(parent)
{
   // btn = new QPushButton(this);
   // btn->setText(val);//设置按钮的名称。
    //btn->setMinimumSize(60,40);

    connect(this,SIGNAL(clicked()),this,SLOT(on_click()));
}

void my_btn::on_click()
{
    qDebug()<<"on_click";
    emit send_val(this->text());
}

