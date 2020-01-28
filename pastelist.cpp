#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtextcodec.h>
#include <mysql/mysql.h>
#include <QTextEdit>
#include <qclipboard.h>
#include <string>
#include <QMessageBox>
#include<iostream>
#include<ctime>
#include <string.h>
using   namespace   std;
extern char MakecodeChar(char c,int key);
extern char CutcodeChar(char c,int key);
extern void Cutecode(char *pstr,int *pkey);
extern int key[];
static   char   convert(wchar_t   n);
static   bool   In(wchar_t   start,   wchar_t   end,   wchar_t   code);
int lists=0;
char * strim(char *str) {
    char *end,*sp,*ep;
    int len;
    sp = str;
    end = str + strlen(str) - 1;
    ep = end;
    while(sp<=end && isspace(*sp))
            sp++;
    while(ep>=sp && isspace(*ep))
            ep--;
    len = (ep < sp) ? 0:(ep-sp)+1;
    sp[len] = '\0';
    return sp;
}
const char* choosepic(char letter) {
    if(letter>=97)
            letter-=32;
    switch(letter) {
        case 'A' :return "/Users/dengjunyuan/deginx-paste/pic/A.png";
        case 'B' :return "/Users/dengjunyuan/deginx-paste/pic/B.png";
        case 'C' :return "/Users/dengjunyuan/deginx-paste/pic/C.png";
        case 'D' :return "/Users/dengjunyuan/deginx-paste/pic/D.png";
        case 'E' :return "/Users/dengjunyuan/deginx-paste/pic/E.png";
        case 'F' :return "/Users/dengjunyuan/deginx-paste/pic/F.png";
        case 'G' :return "/Users/dengjunyuan/deginx-paste/pic/G.png";
        case 'H' :return "/Users/dengjunyuan/deginx-paste/pic/H.png";
        case 'I' :return "/Users/dengjunyuan/deginx-paste/pic/I.png";
        case 'J' :return "/Users/dengjunyuan/deginx-paste/pic/J.png";
        case 'K' :return "/Users/dengjunyuan/deginx-paste/pic/K.png";
        case 'L' :return "/Users/dengjunyuan/deginx-paste/pic/L.png";
        case 'M' :return "/Users/dengjunyuan/deginx-paste/pic/M.png";
        case 'N' :return "/Users/dengjunyuan/deginx-paste/pic/N.png";
        case 'O' :return "/Users/dengjunyuan/deginx-paste/pic/O.png";
        case 'P' :return "/Users/dengjunyuan/deginx-paste/pic/P.png";
        case 'Q' :return "/Users/dengjunyuan/deginx-paste/pic/Q.png";
        case 'R' :return "/Users/dengjunyuan/deginx-paste/pic/R.png";
        case 'S' :return "/Users/dengjunyuan/deginx-paste/pic/S.png";
        case 'T' :return "/Users/dengjunyuan/deginx-paste/pic/T.png";
        case 'U' :return "/Users/dengjunyuan/deginx-paste/pic/U.png";
        case 'V' :return "/Users/dengjunyuan/deginx-paste/pic/V.png";
        case 'W' :return "/Users/dengjunyuan/deginx-paste/pic/W.png";
        case 'X' :return "/Users/dengjunyuan/deginx-paste/pic/X.png";
        case 'Y' :return "/Users/dengjunyuan/deginx-paste/pic/Y.png";
        case 'Z' :return "/Users/dengjunyuan/deginx-paste/pic/Z.png";
        case '1' :return "/Users/dengjunyuan/deginx-paste/pic/1.png";
        case '2' :return "/Users/dengjunyuan/deginx-paste/pic/2.png";
        case '3' :return "/Users/dengjunyuan/deginx-paste/pic/3.png";
        case '4' :return "/Users/dengjunyuan/deginx-paste/pic/4.png";
        case '5' :return "/Users/dengjunyuan/deginx-paste/pic/5.png";
        case '6' :return "/Users/dengjunyuan/deginx-paste/pic/6.png";
        case '7' :return "/Users/dengjunyuan/deginx-paste/pic/7.png";
        case '8' :return "/Users/dengjunyuan/deginx-paste/pic/8.png";
        case '9' :return "/Users/dengjunyuan/deginx-paste/pic/9.png";
        case '0' :return "/Users/dengjunyuan/deginx-paste/pic/0.png";
        case '+' :return "/Users/dengjunyuan/deginx-paste/pic/加号.png";
        case '%' :return "/Users/dengjunyuan/deginx-paste/pic/百分号.png";
        case '*' :return "/Users/dengjunyuan/deginx-paste/pic/乘号.png";
        case '-' :return "/Users/dengjunyuan/deginx-paste/pic/减号.png";
        case '.' :return "/Users/dengjunyuan/deginx-paste/pic/小数点.png";
        case '(' :return "/Users/dengjunyuan/deginx-paste/pic/左括号.png";
        case ')' :return "/Users/dengjunyuan/deginx-paste/pic/右括号.png";
        case '/' :return "/Users/dengjunyuan/deginx-paste/pic/除号.png";
        case '#' :return "/Users/dengjunyuan/deginx-paste/pic/icon-井.png";
        case '@' :return "/Users/dengjunyuan/deginx-paste/pic/艾特.png";
        case '~' :return "/Users/dengjunyuan/deginx-paste/pic/波浪能.png";
        case '=' :return "/Users/dengjunyuan/deginx-paste/pic/等于.png";
        case '>' :return "/Users/dengjunyuan/deginx-paste/pic/大于号.png";
        case '!' :return "/Users/dengjunyuan/deginx-paste/pic/感叹号.png";
        case '$' :return "/Users/dengjunyuan/deginx-paste/pic/美元.png";
        case '<' :return "/Users/dengjunyuan/deginx-paste/pic/小于号.png";
        case ':' :return "/Users/dengjunyuan/deginx-paste/pic/数字冒号.png";
        case ' ' :return "/Users/dengjunyuan/deginx-paste/pic/去除空格.png";
        case '[' :return "/Users/dengjunyuan/deginx-paste/pic/括号_brackets.png";
        case ']' :return "/Users/dengjunyuan/deginx-paste/pic/括号_brackets.png";


    }
    return "uknow";
}
char   convert(wchar_t   n) {
    if   (In(0xB0A1,0xB0C4,n))   return   'a';
    if   (In(0XB0C5,0XB2C0,n))   return   'b';
    if   (In(0xB2C1,0xB4ED,n))   return   'c';
    if   (In(0xB4EE,0xB6E9,n))   return   'd';
    if   (In(0xB6EA,0xB7A1,n))   return   'e';
    if   (In(0xB7A2,0xB8c0,n))   return   'f';
    if   (In(0xB8C1,0xB9FD,n))   return   'g';
    if   (In(0xB9FE,0xBBF6,n))   return   'h';
    if   (In(0xBBF7,0xBFA5,n))   return   'j';
    if   (In(0xBFA6,0xC0AB,n))   return   'k';
    if   (In(0xC0AC,0xC2E7,n))   return   'l';
    if   (In(0xC2E8,0xC4C2,n))   return   'm';
    if   (In(0xC4C3,0xC5B5,n))   return   'n';
    if   (In(0xC5B6,0xC5BD,n))   return   'o';
    if   (In(0xC5BE,0xC6D9,n))   return   'p';
    if   (In(0xC6DA,0xC8BA,n))   return   'q';
    if   (In(0xC8BB,0xC8F5,n))   return   'r';
    if   (In(0xC8F6,0xCBF0,n))   return   's';
    if   (In(0xCBFA,0xCDD9,n))   return   't';
    if   (In(0xCDDA,0xCEF3,n))   return   'w';
    if   (In(0xCEF4,0xD188,n))   return   'x';
    if   (In(0xD1B9,0xD4D0,n))   return   'y';
    if   (In(0xD4D1,0xD7F9,n))   return   'z';
    return   '\0';
}
bool   In(wchar_t   start,   wchar_t   end,   wchar_t   code) {
    if   (code   >=   start   &&   code   <=   end) {
        return   true;
    }
    return   false;
}
char* engtochn(string   sChinese) {
    char   chr[3];
    wchar_t   wchr   =   0;
    int len = sChinese.length()/2;
    char*   buff   = new   char[len];
    memset(buff,   0x00,   sizeof(char)*sChinese.length()/2+1);
    for (unsigned long   i   =   0,   j   =   0;   i   <   (sChinese.length()/2);   ++i) {
        memset(chr,   0x00,   sizeof(chr));
        chr[0]   =   sChinese[j++];
        chr[1]   =   sChinese[j++];
        chr[2]   =   '\0';
        wchr   =   0;
        wchr   =   (chr[0]   &   0xff)   <<   8;
        wchr   |=   (chr[1]   &   0xff);
        buff[i]   =   convert(wchr);
    }
    return buff;

}
void pastelistThread::run() {

    QTextCodec *codec = QTextCodec::codecForName("gbk");
    MYSQL mydata;
    MYSQL_ROW row;
    MYSQL_RES *result;
    unsigned long long rowcount=60000;
    mysql_library_init(0, NULL, NULL);
    mysql_init(&mydata);
    mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk");
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
    while(1) {
        mysql_query(&mydata,str.c_str());
        result = mysql_store_result(&mydata);
        if(rowcount == mysql_num_rows(result))
                continue; else
            rowcount = mysql_num_rows(result);
        QListWidgetItem * pItem = new QListWidgetItem;
        if(lists==0)
        {
            emit SendUI(pItem,1);
            for (unsigned long long i=0;i<rowcount;i++) {
            row = mysql_fetch_row(result);
            pItem = new QListWidgetItem;
            pItem->setSizeHint(QSize(0, 60));
            pItem->setText(codec->toUnicode(strim(row[0])));
            //pItem->setText(strim(row[0]));
            if(strcmp(choosepic(strim(row[0])[0]),"uknow")!=0) {
                pItem->setIcon(QIcon(choosepic(strim(row[0])[0])));
            } else {
                if(strcmp(choosepic(engtochn(strim(row[0]))[0]),"uknow")!=0)
                pItem->setIcon(QIcon(choosepic(engtochn(strim(row[0]))[0])));
                else
                pItem->setIcon(QIcon("/Users/dengjunyuan/deginx-paste/pic/没有.png"));
            }
            emit SendUI(pItem,0);
        }
            lists++;
        }else{
            for (unsigned long long i=0;i<rowcount;i++)
            row = mysql_fetch_row(result);
            pItem = new QListWidgetItem;
            pItem->setSizeHint(QSize(0, 60));
            pItem->setText(codec->toUnicode(strim(row[0])));
            //pItem->setText(strim(row[0]));
            if(strcmp(choosepic(strim(row[0])[0]),"uknow")!=0) {
                pItem->setIcon(QIcon(choosepic(strim(row[0])[0])));
            } else {
                if(strcmp(choosepic(engtochn(strim(row[0]))[0]),"uknow")!=0)
                pItem->setIcon(QIcon(choosepic(engtochn(strim(row[0]))[0])));
                else
                pItem->setIcon(QIcon("/Users/dengjunyuan/deginx-paste/pic/没有.png"));
            }
            emit SendUI(pItem,0);
        }

        mysql_free_result(result);
    }
    mysql_close(&mydata);
}
