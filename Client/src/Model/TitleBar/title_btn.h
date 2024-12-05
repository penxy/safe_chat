#pragma once

#include "config.h"
#include "Base/btn_base.h"
#include <QMouseEvent>

class TitleBtn : public BtnBase{
public:
    explicit TitleBtn(QStringList&& path_list, QWidget *parent = nullptr) : BtnBase(std::move(path_list), parent) {
        setFixedSize(40, 30);
        setFlat(true);
        setStyleSheet("border:none");
    }
protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            Q_UNUSED(event);
            if(m_path_press != nullptr){
                setIcon(QIcon(*m_path_press));
            }
            emit clicked();
        }
    }
};