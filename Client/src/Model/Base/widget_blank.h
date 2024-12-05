#ifndef __WIDGET_BLANK_H__
#define __WIDGET_BLANK_H__

#include <QWidget>

/**
 * @class WidgetBlank
 * @brief 空的QWidget
 */
class WidgetBlank : public QWidget{
    Q_OBJECT
public:
    explicit WidgetBlank(QWidget *parent = nullptr);
};

#endif // __WIDGET_BLANK_H__