#include "tool_btn.h"
#include "config.h"

#include <QBitmap>
#include <QPixmap>
#include <QPainter>
#include <unistd.h>

ToolBtn::ToolBtn(QStringList&& path_list, QWidget *parent) : BtnBase(std::move(path_list), parent){
    setFixedSize(sz::tool_btn);
    setIconSize(sz::tool_btn);
    setStyleSheet("border:none;");
}

void ToolBtn::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        Q_UNUSED(event);
        if(m_path_press != nullptr){
            setIcon(QIcon(*m_path_press));
        }
        emit clicked();
    }
}
// 
/*
//画个框
        QSize size(CONST_SIZE_BTN_TOOL);
        QBitmap mask(size);
        QPainter painter(&mask);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
        painter.setBrush(QColor(0, 0, 0));
        painter.drawRoundedRect(0, 0, size.width(), size.height(), 99, 99);

        QPixmap image;
        image.scaled(size);
        image.setMask(mask);
        
        setIcon(QIcon(image));
        setIconSize(this->size());
        setStyleSheet("border:none;");

*/