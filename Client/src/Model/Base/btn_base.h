#pragma once
#include <QPushButton>
#include <QEvent>
#include <QIcon>
#include <QDebug>

class BtnBase : public QPushButton{
public:
    explicit BtnBase(QStringList&& path_list, QWidget *parent = nullptr) : QPushButton(parent) {
        if(path_list.size() == 1){
            m_path_move_out = new QString(path_list[0]);
        } else if(path_list.size() == 2){
            m_path_move_in = new QString(path_list[0]);
            m_path_move_out = new QString(path_list[1]);
        } else {
            m_path_move_in = new QString(path_list[0]);
            m_path_move_out = new QString(path_list[1]);
            m_path_press = new QString(path_list[2]);
        }
        setIcon(QIcon(*m_path_move_out));
    }
protected:
    void enterEvent(QEvent *event){
        if(m_path_move_in != nullptr){
            setIcon(QIcon(*m_path_move_in));
        }
        // event->accept();
    }
    void leaveEvent(QEvent *event){
        setIcon(QIcon(*m_path_move_out));
        // event->accept();
    }
    void mousePressEvent(QMouseEvent *event){
        Q_UNUSED(event);
        if(m_path_press != nullptr){
            setIcon(QIcon(*m_path_press));
        }
    }
protected:
    QString *m_path_move_in = nullptr;
    QString *m_path_move_out = nullptr;//default
    QString *m_path_press = nullptr;
};