#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtextcodec.h>
#include <mysql/mysql.h>
#include <QTextEdit>
#include <qclipboard.h>
#include <string.h>
#include <QTextCodec>
#include<iostream>
#include<ctime>
using namespace std;
extern char MakecodeChar(char c,int key);
extern char CutcodeChar(char c,int key);
extern void Cutecode(char *pstr,int *pkey);
extern int key[];
void pasteThread::run()
{
    QClipboard *clipboard = QApplication::clipboard();
    MYSQL mydata;
    MYSQL_ROW row;
    MYSQL_RES *result;
    string clipboardtext;
    int rowcount;
    int times;
    mysql_library_init(0, NULL, NULL);
    mysql_init(&mydata);
    mysql_real_connect(&mydata, "linux.deginx.com", "Dpasteplusplus", "b17535039a", "Dpasteplusplus", 3306, NULL, 0);
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
        times = mysql_num_rows(result);
    while(1)
    {
        string text;
        string sqltext;
    int i=0;
    mysql_query(&mydata,str.c_str());
    result = mysql_store_result(&mydata);
    rowcount = mysql_num_rows(result);
    for(i=0;i<rowcount;i++)
    {
        row = mysql_fetch_row(result);
    }
    clipboardtext=clipboard->text().toStdString();
    if(rowcount!=0)
    {
        if(strcmp(row[0],clipboard->text().toStdString().c_str())==0)
        continue;
    else{
            if(times<rowcount)
        {
                clipboard->setText(row[0]);
                times++;
            }else{
                sqltext=QObject::tr(clipboard->text().toStdString().c_str()).toStdString();
        text="INSERT INTO  `"+s+"` (text,synchronous) VALUES('"+sqltext+"','yes')";
        mysql_query(&mydata,text.c_str());
        times++;
            }
        }
    }
    else{
        sqltext=QObject::tr(clipboard->text().toStdString().c_str()).toStdString();
         text="INSERT INTO  `"+s+"` (text,synchronous) VALUES('"+sqltext+"','yes')";
        mysql_query(&mydata,text.c_str());
        times++;
        }
    mysql_free_result(result);
    }
mysql_close(&mydata);

}

