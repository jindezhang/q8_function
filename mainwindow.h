#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMouseEvent>
#include "analysis.h"
#include <string>
#include <algorithm>
#include <QString>
#include "my_btn.h"

//加号不代表正数，- 只有在首部才会不用括号代表负数
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event);
    void init_btn();
    bool is_ast(string str);
    bool is_ast_after();

    void pre_dealstr(QString &str);//预处理字符 ->*
    void pre_log(QString &str);
    bool pre_symbol(QString str);//检查首尾，符号连续
    void check_expression();
private slots:
    void on_pushButton_clicked();
    void get_project(QString name);

private:
    Ui::MainWindow *ui;
    analysis *ana;
    void line_changeColor(bool b);
};

#endif // MAINWINDOW_H
