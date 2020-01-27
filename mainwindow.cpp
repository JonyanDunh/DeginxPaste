#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextEdit>
#include <qclipboard.h>
#include <string>
#include <qtextcodec.h>
#include <mysql/mysql.h>
#include <QMetaType>
#include<iostream>
#include<ctime>
//单个字符异或运算
char MakecodeChar(char c,int key){
    return c=c^key;
}
//单个字符解密
char CutcodeChar(char c,int key){
    return c^key;
}

void Cutecode(char *pstr,int *pkey){
    int len=strlen(pstr);
    for(int i=0;i<len;i++)
        *(pstr+i)=CutcodeChar(*(pstr+i),pkey[i%5]);
}
int key[]={21,71,34,49,11};
extern int lists;
using namespace std;
extern int times;
extern char * strim(char *str);
extern char* engtochn(string   sChinese);
extern const char* choosepic(char letter);
int setflats=1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    chickuserlogin();
    setWindowFlags (Qt::FramelessWindowHint);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    ui->listWidget->setStyleSheet(
    "QListWidget::Item:hover{background:#FF3F80; color:#FFFFFF;}"//鼠标经过的颜色
    "QListWidget::item:selected{background:#3E50B4; color:#FFFFFF; }"//点击的颜色
    "QListWidget::item{ border-bottom: 1px solid 	#A9A9A9; }"//分割线
    );
    QPalette pal;
    //设置调色板
    //背景颜色透明
    pal.setColor(QPalette::Text,QColor(120,120,120));
    ui->listWidget->setPalette(pal);
    pal.setColor(QPalette::Base,QColor(255,255,255,1));
    ui->lineEdit->setPalette(pal);
    //应用调色板
    QListWidgetItem *add_item = new QListWidgetItem(ui->listWidget);
    add_item->setTextAlignment(Qt::AlignHCenter);
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //关闭水平滚动条
    ui->listWidget->sortItems(Qt::DescendingOrder);
    //倒序
    ui->listWidget->setFrameShape(QListWidget::NoFrame);
    //无边框
    ui->listWidget->setIconSize(QSize(40,40));
    //图标大小
    connect(ui->clean, SIGNAL(triggered()), this, SLOT(chickclean()));
    connect(ui->synchronous, SIGNAL(triggered()), this, SLOT(chicksynchronous()));
    connect(ui->actionexit, SIGNAL(triggered()), this, SLOT(logins()));
    pasteThread *startpaste = new pasteThread();
    startpastelist = new pastelistThread();
    connect(startpastelist, SIGNAL(SendUI(QListWidgetItem *,int)), this, SLOT(ShowInfo(QListWidgetItem *,int)));
    startpastelist->start();
    startpaste->start();
}
MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::on_listWidget_clicked(const QModelIndex &) {
    int currenRow = ui->listWidget->currentRow();
    QClipboard *clipboard = QApplication::clipboard();
    MYSQL mydata;
    MYSQL_ROW row;
    MYSQL_RES *result;
    int rowcount;
    mysql_library_init(0, NULL, NULL);
    mysql_init(&mydata);
    mysql_real_connect(&mydata, "linux.deginx.com", "root", "A072107", "Dpasteplusplus", 3306, NULL, 0);
    string s;
    ifstream File("./Dpaste.dcofig");
    getline(File,s);
    int nLen = strlen(s.c_str());
        char *buf = new char[nLen + 1];
        strcpy(buf, s.c_str());
    Cutecode(buf,key);
    s=buf;
   string str = "SELECT text FROM `"+s+"`";
    File.close();
    mysql_query(&mydata,str.c_str());
    result = mysql_store_result(&mydata);
    rowcount = mysql_num_rows(result);
    for (int i=0;i<rowcount-currenRow;i++) {
        row = mysql_fetch_row(result);
    }
    clipboard->clear();
    clipboard->setText(row[0]);
    mysql_free_result(result);
    mysql_close(&mydata);
}
void MainWindow::ShowInfo(QListWidgetItem *pItem,int i) {
    if(i==0)
        ui->listWidget->insertItem(0, pItem); else if(i==1)
            ui->listWidget->clear();
    lists=0;
}
void MainWindow::chickclean()
{

    MYSQL mydata;
    mysql_library_init(0, NULL, NULL);
    mysql_init(&mydata);
    mysql_real_connect(&mydata, "linux.deginx.com", "root", "A072107", "Dpasteplusplus", 3306, NULL, 0);
    string s;
    ifstream File("./Dpaste.dcofig");
    getline(File,s);
    int nLen = strlen(s.c_str());
        char *buf = new char[nLen + 1];
        strcpy(buf, s.c_str());
    Cutecode(buf,key);
    s=buf;
    string str = "truncate table `"+s+"`";
    File.close();
    mysql_query(&mydata,str.c_str());
}
void MainWindow::chicksynchronous()
{
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    ui->listWidget->clear();
    MYSQL mydata;
    MYSQL_ROW row;
    MYSQL_RES *result;
    unsigned long long rowcount=60000;
    mysql_library_init(0, NULL, NULL);
    mysql_init(&mydata);
    mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk");
    mysql_real_connect(&mydata, "linux.deginx.com", "root", "A072107", "Dpasteplusplus", 3306, NULL, 0);
    string s;
    ifstream File("./Dpaste.dcofig");
    getline(File,s);
    int nLen = strlen(s.c_str());
        char *buf = new char[nLen + 1];
        strcpy(buf, s.c_str());
    Cutecode(buf,key);
    s=buf;
string str = "SELECT text FROM `"+s+"`";
    File.close();
    mysql_query(&mydata,str.c_str());
    result = mysql_store_result(&mydata);
        rowcount = mysql_num_rows(result);
    QListWidgetItem * pItem = new QListWidgetItem;
    for (unsigned long long i=0;i<rowcount;i++)
    {
        row = mysql_fetch_row(result);
        pItem = new QListWidgetItem;
        pItem->setSizeHint(QSize(0, 60));
        pItem->setText(codec->toUnicode(strim(row[0])));
        if(strcmp(choosepic(strim(row[0])[0]),"uknow")!=0) {
            pItem->setIcon(QIcon(choosepic(strim(row[0])[0])));
        } else {
            if(strcmp(choosepic(engtochn(strim(row[0]))[0]),"uknow")!=0)
            pItem->setIcon(QIcon(choosepic(engtochn(strim(row[0]))[0])));
            else
            pItem->setIcon(QIcon("/Users/dengjunyuan/Pictures/letter/没有.png"));
        }
        ui->listWidget->insertItem(0, pItem);
    }
    mysql_free_result(result);
    mysql_close(&mydata);
}
void MainWindow::on_lineEdit_textChanged(const QString &)
{if(ui->lineEdit->text().isEmpty())
chicksynchronous();
    else{
    ui->listWidget->clear();
    MYSQL mydata;
    MYSQL_ROW row;
    MYSQL_RES *result;
    string sqltext=ui->lineEdit->text().toStdString();
    int rowcount;
    mysql_library_init(0, NULL, NULL);
    mysql_init(&mydata);
    mysql_real_connect(&mydata, "linux.deginx.com", "root", "A072107", "Dpasteplusplus", 3306, NULL, 0);
    string s;
    ifstream File("./Dpaste.dcofig");
    getline(File,s);
    File.close();
    int nLen = strlen(s.c_str());
        char *buf = new char[nLen + 1];
        strcpy(buf, s.c_str());
    Cutecode(buf,key);
    s=buf;
    sqltext="SELECT text FROM `"+s+"` where concat(`text` ) like'%"+ ui->lineEdit->text().toStdString()+"%'";

    mysql_query(&mydata,sqltext.c_str());
    result = mysql_store_result(&mydata);
        rowcount = mysql_num_rows(result);
    QListWidgetItem * pItem = new QListWidgetItem;
    for (int i=0;i<rowcount;i++)
    {
        row = mysql_fetch_row(result);
        pItem = new QListWidgetItem;
        pItem->setSizeHint(QSize(0, 60));
        pItem->setText(strim(row[0]));
        if(strcmp(choosepic(strim(row[0])[0]),"uknow")!=0) {
            pItem->setIcon(QIcon(choosepic(    strim(row[0])[0]    )));
        } else {
            if(strcmp(choosepic(engtochn(strim(row[0]))[0]),"uknow")!=0)
            pItem->setIcon(QIcon(choosepic(engtochn(strim(row[0]))[0])));
            else
            pItem->setIcon(QIcon("/Users/dengjunyuan/Pictures/letter/没有.png"));
        }
        ui->listWidget->insertItem(0, pItem);
    }
    mysql_free_result(result);
    mysql_close(&mydata);
    }
}

void MainWindow::on_pushButton_clicked()
{
          Qt::WindowFlags m_flags = windowFlags();

    if(setflats==1)
    {
        setflats=0;
        setWindowFlags(m_flags | Qt::WindowStaysOnTopHint |Qt::FramelessWindowHint);
          show();
    ui->pushButton->setFlat(0);
    }else if(setflats==0)
    {
        setflats=1;
        ui->pushButton->setFlat(1);
        m_flags = NULL;
            setWindowFlags(m_flags|Qt::FramelessWindowHint);
            show();
    }

}
void MainWindow::logins()
{
    remove("./Dpaste.dcofig");
    logindlg = new login;//将类指针实例化
        logindlg->show();
        close();
}
void MainWindow::chickuserlogin()
{

    if (FILE *file = fopen("./Dpaste.dcofig", "r")) {
    MYSQL mydata;
    MYSQL_RES *result;
    int rowcount;
    mysql_library_init(0, NULL, NULL);
    mysql_init(&mydata);
    mysql_real_connect(&mydata, "linux.deginx.com", "root", "A072107", "Dpasteplusplus", 3306, NULL, 0);
    string s;
    ifstream File("./Dpaste.dcofig");
    getline(File,s);
    int nLen = strlen(s.c_str());
        char *buf = new char[nLen + 1];
        strcpy(buf, s.c_str());
    Cutecode(buf,key);
    s=buf;
    string s2;
    getline(File,s2,'\n');
    int nLen2 = strlen(s2.c_str());
        char *buf2 = new char[nLen2 + 1];
        strcpy(buf2, s2.c_str());
        int key2[]={31,45,39,8,6};
    Cutecode(buf2,key2);
    s2=buf2;
   string str = "select mail,password from user where mail='"+s+"' AND password='"+s2+"'";
    File.close();
    mysql_query(&mydata,str.c_str());
    result = mysql_store_result(&mydata);
    rowcount = mysql_num_rows(result);
    if(rowcount==0)
    {
        QMessageBox::warning(this, QObject::tr("错误"),QObject::tr("您的账号或密码错误了!!请重新登录!!"),QMessageBox::Yes);
        logindlg = new login;//将类指针实例化
            logindlg->show();
            close();
    }
}else {
        QMessageBox::warning(this, QObject::tr("错误"),QObject::tr("您的账号或密码错误了!!请重新登录!!"),QMessageBox::Yes);
        logindlg = new login;//将类指针实例化
            logindlg->show();
            close();
    }

}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
        int dy = e->globalY() - last.y();
        last = e->globalPos();
        move(x()+dx, y()+dy);
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void MainWindow::on_pushButton_3_clicked()
{
     close();
}
