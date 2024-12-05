#include "label_role.h"

LabelRole::LabelRole(Type::Role role, QWidget *parent) : QLabel(parent){
    QString qss;
    if(role == Type::Role::Owner){
        qss = "*{background-color: rgb(66, 227, 245);border-radius: 2px;}";
        this->setText(tr("群主"));
    }
    else if (role == Type::Role::Admin){
        qss = "*{background-color: rgb(211, 3, 252);border-radius: 2px;}";
        this->setText(tr("管理员"));
    }
    else{
        qss = "*{background-color: rgb(132, 245, 66);border-radius: 2px;}";
        this->setText(tr("成员"));
    }
    this->setStyleSheet(qss);
    this->setFixedSize(sz::role);
}
