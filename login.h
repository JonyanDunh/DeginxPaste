#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_lineEdit_textChanged(const QString &);

    void on_lineEdit_2_textChanged(const QString &);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void chickclean();

    void chicklogin();

signals:

private:
    Ui::login *ui;

};

#endif // LOGIN_H
