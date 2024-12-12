#pragma once
#include "config.h"

#include <QWidget>
#include <QLabel>

class Friend;
/**
 * @class Member
 * @brief 群成员列表项
 */
class GpMember : public QWidget{
    Q_OBJECT
public:
    explicit GpMember(ns::Member& info, QWidget *parent = nullptr);
private:
    QLabel m_lab_photo;
    QLabel m_lab_name;
    QLabel m_lab_id;
    QLabel m_lab_role;
};
