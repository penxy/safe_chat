#include "widget_login.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

/**
 *@brief 初始化登录界面
 */
void WidgetLogin::init_ui(){
    {
        btn_creat = new QPushButton(this);
        btn_login = new QPushButton(this);
        lab_account = new QLabel(this);
        lab_password = new QLabel(this);
        edit_account = new QLineEdit(this);
        edit_password = new QLineEdit(this);
    }
    {
        btn_creat->setText("create");
        btn_login->setText("login");
        lab_account->setText("account:");
        lab_password->setText("password:");
    }
    {
        btn_creat->setFixedSize(const_size_btn_login);
        btn_login->setFixedSize(const_size_btn_login);
        lab_account->setFixedSize(const_size_lab_login);
        lab_password->setFixedSize(const_size_lab_login);
        edit_account->setFixedSize(const_size_edit_login);
        edit_password->setFixedSize(const_size_edit_login);
        this->setFixedSize(const_size_widget_login);
    }
    
    {
        QWidget* w_account = new QWidget(this);
        QWidget* w_password = new QWidget(this);
        QWidget* w_btn = new QWidget(this);
        {
            QHBoxLayout* layout_account = new QHBoxLayout(this);
            layout_account->addWidget(lab_account);
            layout_account->addWidget(edit_account);
            w_account->setLayout(layout_account);
        }
        {
            QHBoxLayout* layout_password = new QHBoxLayout(this);
            layout_password->addWidget(lab_password);
            layout_password->addWidget(edit_password);
            w_password->setLayout(layout_password);
        }
        {
            QHBoxLayout* layout_btn = new QHBoxLayout(this);
            layout_btn->addWidget(btn_creat);
            layout_btn->addWidget(btn_login);
            w_btn->setLayout(layout_btn);
        }
        {
            QVBoxLayout* layout_main = new QVBoxLayout(this);
            layout_main->addWidget(w_account);
            layout_main->addWidget(w_password);
            layout_main->addWidget(w_btn);
            this->setLayout(layout_main);
        }
    }
}


WidgetLogin::WidgetLogin(QWidget *parent) : QWidget(parent){
    init_ui();


}
