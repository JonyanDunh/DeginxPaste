#pragma once
//#ifndef SIMPLETHREADONE_H
//#define SIMPLETHREADONE_H
#include <QThread>
#include "ui_mainwindow.h"
class pasteThread : public QThread
{
public:
    void run();
};


class pastelistThread : public QThread
{
    Q_OBJECT
public:

    void run();

signals:
    void SendUI(QListWidgetItem *pItem,int i);
};
//#endif // SIMPLETHREADONE_H
