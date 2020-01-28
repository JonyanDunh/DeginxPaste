#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "multithreading.h"
#include "login.h"
#include <fstream>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connectMYSQL();
    pastelistThread *startpastelist;
    void chickuserlogin();
private slots:
    void ShowInfo(QListWidgetItem *pItem,int i);
    void on_listWidget_clicked(const QModelIndex &);
    void chickclean();
   void chicksynchronous();
   void logins();
   void on_lineEdit_textChanged(const QString &);
   void on_pushButton_clicked();
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    Ui::MainWindow *ui;
    login *logindlg;
    QPoint last;
};
#endif // MAINWINDOW_H
