#ifndef WIDGETLOGIN_H
#define WIDGETLOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "widget_const.h"

class WidgetLogin : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetLogin(QWidget *parent = nullptr);
    void init_ui();

private:
    QPushButton* btn_login;
    QPushButton* btn_creat;
    QLineEdit* edit_account;
    QLineEdit* edit_password;
    QLabel* lab_account;
    QLabel* lab_password;

    QWidget* widget_head;
};

#endif // WIDGETLOGIN_H
