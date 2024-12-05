#include "Line.h"
#include <QBoxLayout>

Line::Line(QWidget *parent, TypeLine type) : QFrame(parent){
    if(type == TypeLine::H){
        this->setFrameShape(QFrame::HLine); // 设置为横线
        this->setFrameShadow(QFrame::Sunken); // 设置阴影为凹陷效果
        this->setLineWidth(1); // 设置线宽
        QBoxLayout *layout_line_bottom = new QBoxLayout(QBoxLayout::TopToBottom, this);
        layout_line_bottom->setAlignment(Qt::AlignTop);
    }else{
        this->setFrameShape(QFrame::VLine); // 设置为横线
        this->setFrameShadow(QFrame::Sunken); // 设置阴影为凹陷效果
        this->setLineWidth(1); // 设置线宽
        QBoxLayout *layout_line_bottom = new QBoxLayout(QBoxLayout::LeftToRight, this);
        layout_line_bottom->setAlignment(Qt::AlignLeft);
    }
}