#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("from RD330");
    //安装过滤事件
    init_btn();

    ana = new analysis();

    btn_name.push_back("AST1");
    btn_name.push_back("AST2");
    btn_name.push_back("AST3");

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    QString text_btn;//按键上的值。
    QPushButton *btn;
    QString text_line = ui->lineEdit->text();
    QString val;//传递给analysis 的字符串

    QMouseEvent *mouse = (QMouseEvent *)event;
    if(!((mouse->buttons()&Qt::LeftButton) && event->type()==QEvent::MouseButtonPress))//点击鼠标左键
        return QWidget::eventFilter(watched,event);

    //--------number btn
    if(watched == ui->btn_0 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_1 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_2 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_3 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_4 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_5 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_6 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_7 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_8 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_9 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }

    //-----------------function btn------
    //加减乘除
    if(watched == ui->btn_add && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_sub && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_multiply && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_divider && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }

    //括号点逗号
    if(watched == ui->btn_R && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_L && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_d && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_p && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }

    //特殊功能键
    if(watched == ui->btn_ac && event->type()==QEvent::MouseButtonPress ){
//        清空
        ui->lineEdit->setStyleSheet("background-color:white");
        ui->lineEdit->setText("");
        return QWidget::eventFilter(watched, event);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_bs && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        if(text_line == ""){
            line_changeColor(1);
            goto RETURN;
        }
        text_btn = btn->text();
//mid()函数接受两个参数，第一个是起始位置，第二个是取串的长度。如果省略第二个参数，则会从起始位置截取到末尾
        int i = 0;
        QString val;
        qDebug()<<"text_line[text_line.length()-1]="<<text_line[text_line.length()-1];
        if(text_line[text_line.length()-1] == ']'){
            i = text_line.lastIndexOf("[");
            val = text_line.mid(0,i);
        }else if(text_line[text_line.length()-1] == 'g' || text_line[text_line.length()-1] == 'S'){
            val = text_line.mid(0,text_line.length()-3);
        }
        else
            val = text_line.mid(0,text_line.length()-1);

        ui->lineEdit->setText(val);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_log && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = QString("%1(").arg(btn->text());
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_abs && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = QString("%1(").arg(btn->text());
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_pow && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = "^";
        ui->lineEdit->setText(text_line+text_btn);
//                qDebug()<<"click"<<text_btn;
    }

//    //-------------AST
    if(watched == ui->btn_ast1 && event->type()==QEvent::MouseButtonPress ){
//        //判断是否AST合法
//        string str = ui->lineEdit->text().toStdString();
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+"["+text_btn+"]");

//        if(!is_ast(str))
//        {
//            line_changeColor(0);
//            goto RETURN;
//        }


//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_ast2 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+"["+text_btn+"]");
//                qDebug()<<"click"<<text_btn;
    }
    if(watched == ui->btn_ast3 && event->type()==QEvent::MouseButtonPress ){
        btn = (QPushButton * ) watched;
        text_btn = btn->text();
        ui->lineEdit->setText(text_line+"["+text_btn+"]");
//                qDebug()<<"click"<<text_btn;
    }


//    //-------检查是否输入合法；
//    //检查ASTx 的位置
//    if(is_ast_after()){
//        line_changeColor(1);
//    }else{
//        line_changeColor(0);
//        goto RETURN;
//    }

    //val = ui->lineEdit->text();
//    val.replace("AST1","10");
//    val.replace("AST2","20");
//    val.replace("AST3","30");

    check_expression();
RETURN:
    return QWidget::eventFilter(watched, event);//不能返回true 不然按钮会消失
}

void MainWindow::init_btn()
{
    ui->btn_0->installEventFilter(this);
    ui->btn_1->installEventFilter(this);
    ui->btn_2->installEventFilter(this);
    ui->btn_3->installEventFilter(this);
    ui->btn_4->installEventFilter(this);ui->btn_6->installEventFilter(this);ui->btn_7->installEventFilter(this);
    ui->btn_5->installEventFilter(this);ui->btn_8->installEventFilter(this);ui->btn_9->installEventFilter(this);

    ui->btn_add->installEventFilter(this);ui->btn_sub->installEventFilter(this);ui->btn_multiply->installEventFilter(this);
    ui->btn_divider->installEventFilter(this);ui->btn_R->installEventFilter(this);ui->btn_L->installEventFilter(this);
    ui->btn_d->installEventFilter(this);ui->btn_p->installEventFilter(this);ui->btn_abs->installEventFilter(this);
    ui->btn_ac->installEventFilter(this);ui->btn_log->installEventFilter(this);ui->btn_bs->installEventFilter(this);
    ui->btn_pow->installEventFilter(this);

    ui->btn_ast1->installEventFilter(this);ui->btn_ast2->installEventFilter(this);ui->btn_ast3->installEventFilter(this);
}

bool MainWindow::is_ast(string str)
{
    qDebug()<<"ast_"<<str[str.length()-1];

    if(str.length() == 0)
        return true;

    if(str[str.length()-1]>='0' && str[str.length() -1]<'10')//MYEORRO★ :判断字符是否为数字，需要用到&& 和 '';
        return false;

    return true;
}

bool MainWindow::is_ast_after()
{
    qDebug()<<"is_ast_after_";
    string str = ui->lineEdit->text().toStdString();
    int pos = 0;
    int i = 0;
    while(1){

//        find_first_of()：在一个目标串中进行查找，返回值是第一个与指定字符组中任何字符匹配的字符位置。如果没有查找到匹配的内容，则返回npos。
//        find()：在一个字符串中查找一个指定的单个字符或字符数组。如果找到，就返回首次匹配的开始位置；如果没有查找到匹配的内容，就返回string::npos。
        i = str.find("AST");

        qDebug()<<"i = "<<i<<"  pos= "<<pos <<" length"<<str.length()<<" str="<<QString::fromStdString(str);
        if(i == -1 || (i == 0&&str.length()==4) )//没有找到AST 或者 (AST 是第一个后面没有值）
            return true;

        //左值是数字，同时左值存在
        if(i > 1 && str[i-1]>='0' && str[i -1]<'10')//MYEORRO★ :判断字符是否为数字，需要用到&& 和 '';
        {
            qDebug()<<"L";
            return false;
        }

        //右值是为数字,并且AST不是最后一个
        if((i+4 < str.length()) && str[i+4]>='0' && str[i+4]<'10' )
        {
            qDebug()<<"R";
            return false;
        }


        pos=i+1;
        str = str.substr(pos);
    }

    //return true;
}

void MainWindow::pre_dealstr(QString &str)
{
    QString text = str;
    str = text.replace("/","*");
    str = str.replace("^","*");
    str = str.replace("+","*");
    str = str.replace("ABS","");


    //处理[xx]->(10)
    int i=0;
    int j=0;
    QString tmp;
    while (1) {
        i = str.indexOf('[',j);
        if(-1==i)
            break;
        j = str.indexOf(']',i);
        tmp = str.mid(i,j-i+1);
        str = str.replace(tmp,"(10)");
    }

    //负数的处理。-1 or (-1)
    if(str[0] == '-')
        str = str.mid(1);

    j=0;
    while(1){
        i = str.indexOf("(-");
        if(-1 == i)
            break;
        str = str.mid(0,i+1)+str.mid(i+2);
    }



    //处理log
    j = 0;
    while(1){
        i = str.indexOf("log");
        if(-1 == i)
            break;
        str = str.mid(0,i)+str.mid(i+3);
        j++;
    }
    //逗号已经修改了
//    if(j == str.count(","))
//        str = str.replace(",","+");
//    else
//        str = text;
    qDebug()<<"pre_dealstr str "<<str;

}

void MainWindow::pre_log(QString &str)
{
    QString tmp;
    tmp = str;
    int i = tmp.indexOf("log");
    if(i == -1 )//当log不存在的时候。
        return ;

    tmp = tmp.mid(i+1);
    qDebug()<<"tmp="<<tmp;

    //只有一个log的时候,因为已经第一个被截取了，所以再找不到log
    if(tmp.indexOf("log") == -1)
    {
        int l = 0;
        int i = tmp.indexOf(",");
        if(i == -1){
            str = str.replace("log","loog");
            return;
        }
        QString tmp1 = tmp.mid(0,i);
        QString tmp2 = tmp1;
//        tmp2 = tmp2.mid(tmp2.indexOf("(")+1);
        //，左边的（多一个。
        while(tmp2.indexOf("(") != -1){
            l++;
            tmp2 = tmp2.mid(tmp2.indexOf("(")+1);
        }
        tmp2 = tmp1;
        while(tmp2.indexOf(")") != -1){
            l--;
            tmp2 = tmp2.mid(tmp2.indexOf(")")+1);
        }
        //不对的时候，，->**
        tmp2 = tmp;
        if(l != 1){
            tmp = tmp.replace(",","**");
            str = str.replace(tmp2,tmp);
        }
        else{
            tmp = tmp.replace(",","*");
            str = str.replace(tmp2,tmp);
        }

        qDebug()<<"tmp1="<<tmp1<<"  l="<<l <<"str="<<str;

    }
    else//递归
    {
        QString tmp1 = tmp;
        pre_log(tmp);
        str = str.replace(tmp1,tmp);
    }




}

bool MainWindow::pre_symbol(QString str)
{
    //-,*,(,) 在收尾时候，不合法
    if(str[0] == '*'||str[0] == ')'||str[str.length()-1] == '*'||str[str.length()-1] == '(' || str[str.length()-1] == '-'){
        qDebug()<<"symbol failed";
        return false;
    }
    //符号连续不合法
    if(str.contains("**")||str.contains("*-")||str.contains("-*")||str.contains("--")){
        qDebug()<<"** symbol failed";
        return false;
    }

    //( != )
    if(str.count('(') != str.count(')')){
        qDebug()<<"() symbol failed";
        return false;
    }

    //（ 不是首部且左边是num，）；右边是），*
//    string tmp = str.toStdString();
//    while(tmp.find('(',pos))
//    if(())

    return true;

}

void MainWindow::check_expression()
{
    //  test
    QString val = ui->lineEdit->text();
    pre_log(val);
    pre_dealstr(val);
    //pre_symbol(text_btn);
//    //检查表达式
    if(!ana->is_analysis(val.toStdString())){
        qDebug()<<"call is_analysis();";
        ui->lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);");
    }else
    {
        ui->lineEdit->setStyleSheet("background-color:white");
    }

}

void MainWindow::line_changeColor(bool b)
{
    qDebug()<<"line_"<<b;
    if(b)
        ui->lineEdit->setStyleSheet("background-color:white");
    else
      ui->lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);");
}

void MainWindow::on_pushButton_clicked()
{

    static int i = 0;
    QString text_line = ui->edit_btn_name->text();
    if(text_line == ""){
        QMessageBox::information(this,"eorro","project name is null");
        return;
    }
    for(auto item : btn_name){
        if(item == text_line){
            QMessageBox::information(this,"inform","project name is exist");
            return;
        }
    }
    qDebug()<<"on_pushButton_clicked=";
    my_btn *btn = new  my_btn(text_line);


    connect(btn, SIGNAL(send_val(QString)),this,SLOT(get_project(QString)));

//    取得布局管理器
    QGridLayout *gridLayout = static_cast<QGridLayout*>(ui->wg_btn->layout());
    gridLayout->addWidget(btn,i/3+2,i%3);
    //gridLayout->setRowMinimumHeight(i/3+2,40);
    i++;

    btn_name.push_back(text_line);
}

void MainWindow::get_project(QString name)
{

    QString text_line = ui->lineEdit->text();
    ui->lineEdit->setText(text_line+"["+name+"]");

    check_expression();
}
