#include "login.h"
#include "ui_login.h"
#include <QPixmap>
#include <QBitmap>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QObject>
#include <mysql/mysql.h>
#include <string>
#include <string.h>
#include <QMessageBox>
#include <QApplication>
#include "mainwindow.h"
#include <fstream>
#include <stdio.h>
#include<iostream>
#include<ctime>
using namespace std;
int chickjiantou=0;

//单个字符异或运算
char MakecodeChars(char c,int key){
    return c=c^key;
}
//单个字符解密
char CutcodeChars(char c,int key){
    return c^key;
}

void Makecodes(char *pstr,int *pkey){
    int len=strlen(pstr);//获取长度
    for(int i=0;i<len;i++)
        *(pstr+i)=MakecodeChars(*(pstr+i),pkey[i%5]);
}
void login::chickclean()
{
ui->lineEdit->clear();
}
void login::chicklogin()
{
    string sqltext=ui->lineEdit->text().toStdString();
    MYSQL mydata;
    MYSQL_ROW row;
    MYSQL_RES *result;
    int rowcount;
    mysql_library_init(0, NULL, NULL);
    mysql_init(&mydata);
    //mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk");
    mysql_real_connect(&mydata, "linux.deginx.com", "Dpasteplusplus", "b17535039a", "Dpasteplusplus", 3306, NULL, 0);
    sqltext="select * from user where mail ='"+ sqltext+"'";
    mysql_query(&mydata,sqltext.c_str() );
    result = mysql_store_result(&mydata);
        rowcount = mysql_num_rows(result);
        if(rowcount!=0)
        {
        row = mysql_fetch_row(result);
    if(strcmp(row[3],ui->lineEdit_2->text().toStdString().c_str()  )==0)
    {
        int key[]={21,71,34,49,11};
        Makecodes(row[0],key);
            fstream File("./Dpaste.dcofig", ios::in | ios::out | ios::trunc);
            File <<row[0]<< endl;
            int key2[]={31,45,39,8,6};
            Makecodes(row[3],key2);
            File <<row[3]<< endl;
        MainWindow *MainWindowdlg = new MainWindow;
        this->close();
       MainWindowdlg->show();
    }
    else
    {
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label_2->setPalette(pa);
        ui->label_2->setText("密码错误啦");
    }
        }else{

            QPalette pa;
            pa.setColor(QPalette::WindowText,Qt::red);
            ui->label_2->setPalette(pa);
            ui->label_2->setText("该账号不存在");
        }

    mysql_free_result(result);
    mysql_close(&mydata);

}
QPushButton* createLineEditRightButton(QLineEdit *edit) {
    QPushButton *button = new QPushButton();
    QHBoxLayout *layout = new QHBoxLayout();
    button->setCursor(Qt::ArrowCursor);
    layout->addStretch();
    layout->addWidget(button);
    layout->setContentsMargins(0, 0, 0, 0);
    edit->setLayout(layout);
    return button;
}

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
        ui->setupUi(this);
    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
            setWindowFlags (Qt::FramelessWindowHint);
            QPalette palette(this->palette());
            palette.setColor(QPalette::Background, Qt::white);
            this->setPalette(palette);
    QPalette pal;
    pal.setColor(QPalette::Text,QColor(120,120,120));
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit->setPalette(pal);
    ui->lineEdit_2->setPalette(pal);
    ui->lineEdit->setAlignment( Qt::AlignHCenter);
    ui->lineEdit_2->setAlignment( Qt::AlignHCenter);
    ui->lineEdit_2->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->lineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    ui->pushButton->setFlat(1);
    ui->pushButton->setStyleSheet(
    "QPushButton{border-image: url(/Users/dengjunyuan/Pictures/letter/注册头像.png);border-top: 1px transparent;border-bottom: 1px transparent;border-right: 7px transparent;border-left: 7px transparent;height:20px;border: 0px solid yello;}"
    );
    ui->pushButton_2->setStyleSheet(
                "QPushButton {width:  30px;height: 30px;qproperty-flat: true;margin-right: 4px;border: none;border-width: 0;border-image: url(/Users/dengjunyuan/Pictures/letter/下箭头.png) 0 0 0 0 stretch stretch;}"
                );

    if (FILE *file = fopen("./Dpaste.dcofig", "r"))
    {
            fclose(file);
            MainWindow *MainWindowdlg = new MainWindow;
            MainWindowdlg->show();
            close();
        }
}

login::~login()
{
    delete ui;
}

void login::on_lineEdit_textChanged(const QString &)
{

    ui->label_2->clear();
     QPushButton *button = nullptr;
     button = createLineEditRightButton(ui->lineEdit);
    if(!ui->lineEdit->text().isEmpty())
    {
        button->setStyleSheet(
        "QPushButton {width:  30px;height: 30px;qproperty-flat: true;margin-right: 4px;border: none;border-width: 0;border-image: url(/Users/dengjunyuan/Pictures/letter/删除.png) 0 0 0 0 stretch stretch;}"
        );
        ui->lineEdit_2->setStyleSheet("background:transparent;border-width:1;border-style:outset;border: 1px solid #00BFFF;");
        ui->lineEdit_2->setEnabled(1);
            //button->setVisible(1);;
            connect(button, SIGNAL(clicked()), this, SLOT(chickclean()));
    }else if(ui->lineEdit->text().isEmpty())
    {

        ui->lineEdit_2->setStyleSheet("background:transparent;border-width:0;border-style:outset");
        ui->lineEdit_2->clear();
        ui->lineEdit_2->setEnabled(false);
    }


}

void login::on_lineEdit_2_textChanged(const QString &)
{
    ui->label_2->clear();
    QPushButton *button2;
    button2 = createLineEditRightButton(ui->lineEdit_2);
                button2->setStyleSheet(
                "QPushButton {width:  30px;height: 30px;qproperty-flat: true;margin-right: 4px;border: none;border-width: 0;border-image: url(/Users/dengjunyuan/Pictures/letter/登录.png) 0 0 0 0 stretch stretch;}"
                );
                connect(button2, SIGNAL(clicked()), this, SLOT(chicklogin()));
}

void login::on_pushButton_2_clicked()
{
if(chickjiantou==0)
   {
     this->resize( QSize( 250, 360 ));
    ui->pushButton_2->setStyleSheet(
                "QPushButton {width:  30px;height: 30px;qproperty-flat: true;margin-right: 4px;border: none;border-width: 0;border-image: url(/Users/dengjunyuan/Pictures/letter/上箭头.png) 0 0 0 0 stretch stretch;}"
                );
    chickjiantou=1;
}else if(chickjiantou==1)
{
 this->resize( QSize( 250, 305 ));
 ui->pushButton_2->setStyleSheet(
             "QPushButton {width:  30px;height: 30px;qproperty-flat: true;margin-right: 4px;border: none;border-width: 0;border-image: url(/Users/dengjunyuan/Pictures/letter/下箭头.png) 0 0 0 0 stretch stretch;}"
             );
 chickjiantou=0;
}
}

void login::on_pushButton_3_clicked()
{
    close();
}

