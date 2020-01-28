/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDeginx_paste_toos;
    QAction *actionLogin_registered;
    QAction *synchronous;
    QAction *clean;
    QAction *actionlogin;
    QAction *actionlogin_2;
    QAction *actionexit;
    QAction *actionupdat;
    QAction *actionabout;
    QWidget *centralwidget;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(368, 679);
        QFont font;
        font.setFamily(QStringLiteral(".AppleSystemUIFont"));
        MainWindow->setFont(font);
        actionDeginx_paste_toos = new QAction(MainWindow);
        actionDeginx_paste_toos->setObjectName(QStringLiteral("actionDeginx_paste_toos"));
        actionLogin_registered = new QAction(MainWindow);
        actionLogin_registered->setObjectName(QStringLiteral("actionLogin_registered"));
        synchronous = new QAction(MainWindow);
        synchronous->setObjectName(QStringLiteral("synchronous"));
        synchronous->setCheckable(false);
        synchronous->setChecked(false);
        clean = new QAction(MainWindow);
        clean->setObjectName(QStringLiteral("clean"));
        actionlogin = new QAction(MainWindow);
        actionlogin->setObjectName(QStringLiteral("actionlogin"));
        actionlogin_2 = new QAction(MainWindow);
        actionlogin_2->setObjectName(QStringLiteral("actionlogin_2"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        actionupdat = new QAction(MainWindow);
        actionupdat->setObjectName(QStringLiteral("actionupdat"));
        actionabout = new QAction(MainWindow);
        actionabout->setObjectName(QStringLiteral("actionabout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(2, 70, 371, 591));
        listWidget->setMinimumSize(QSize(371, 541));
        listWidget->setAutoFillBackground(true);
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Sunken);
        listWidget->setLineWidth(0);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        listWidget->setDragEnabled(false);
        listWidget->setDragDropOverwriteMode(false);
        listWidget->setProperty("isWrapping", QVariant(false));
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setWordWrap(false);
        listWidget->setSelectionRectVisible(false);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(19, 30, 331, 21));
        lineEdit->setMaxLength(32767);
        lineEdit->setFrame(true);
        lineEdit->setCursorPosition(0);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(332, 0, 31, 31));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("/Users/dengjunyuan/Pictures/letter/\345\233\276\351\222\211.png");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("../Pictures/letter/\345\233\276\351\222\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton->setIcon(icon);
        pushButton->setFlat(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 368, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(synchronous);
        menu->addAction(clean);
        menu_2->addAction(actionexit);
        menu_2->addAction(actionupdat);
        menu_2->addAction(actionabout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Dpaste++", Q_NULLPTR));
        actionDeginx_paste_toos->setText(QApplication::translate("MainWindow", "Deginx-paste-toos", Q_NULLPTR));
        actionLogin_registered->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225/\346\263\250\345\206\214", Q_NULLPTR));
        synchronous->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\346\211\200\346\234\211\347\262\230\350\264\264\347\211\210", Q_NULLPTR));
        synchronous->setIconText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\346\211\200\346\234\211\347\262\230\350\264\264\347\211\210", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        synchronous->setToolTip(QApplication::translate("MainWindow", "\345\220\214\346\255\245\346\211\200\346\234\211\347\262\230\350\264\264\347\211\210", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        clean->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\211\200\346\234\211\347\262\230\350\264\264\347\211\210", Q_NULLPTR));
        clean->setIconText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\211\200\346\234\211\347\262\230\350\264\264\347\211\210", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        clean->setToolTip(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\211\200\346\234\211\347\262\230\350\264\264\347\211\210", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionlogin->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        actionlogin->setIconText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionlogin->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionlogin_2->setText(QApplication::translate("MainWindow", "login", Q_NULLPTR));
        actionexit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        actionupdat->setText(QApplication::translate("MainWindow", "\346\243\200\346\237\245\346\233\264\346\226\260", Q_NULLPTR));
        actionabout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\255\244\350\275\257\344\273\266", Q_NULLPTR));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        pushButton->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\347\262\230\350\264\264\347\211\210", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\233\264\345\244\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
