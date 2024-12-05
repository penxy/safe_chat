#pragma once

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>

/**
 * @class WidBase
 * @brief 主要窗口的基类
 * @note 主要是为了实现窗口拖动，后续可以扩展然后实现窗口缩放
 */
class WidBase : public QMainWindow{
    Q_OBJECT
public:
    WidBase(QMainWindow *parent = nullptr);
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    bool mouse_press;
    QPoint mousePoint;
};


