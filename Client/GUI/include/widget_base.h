#ifndef WIDGETBASE_H
#define WIDGETBASE_H

#include <QWidget>

class WidgetBase : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetBase(QWidget *parent = 0);
    ~WidgetBase() = default;

private:
    QPoint dragPosition;   //鼠标拖动的位置
    const int edgeMargin = 4;     //鼠标检测的边缘距离
    enum {nodir,
          top = 0x01,
          bottom = 0x02,
          left = 0x04,
          right = 0x08,
          topLeft = 0x01 | 0x04,
          topRight = 0x01 | 0x08,
          bottomLeft = 0x02 | 0x04,
          bottomRight = 0x02 | 0x08} resizeDir; //更改尺寸的方向

private:
    void testEdge();  //检测鼠标是否接近窗口边缘
protected:
    void mousePressEvent(QMouseEvent*event);
    void mouseMoveEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
};

#endif // WIDGETBASE_H
