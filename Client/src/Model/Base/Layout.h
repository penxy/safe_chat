#ifndef __LAYOUT_H__
#define __LAYOUT_H__


#include <QBoxLayout>

/**
 * @brief Margin = 0的QBoxLayout
 */
class Layout : public QBoxLayout{
public:
    Layout(QBoxLayout::Direction direction, QWidget *parent = 0);
};



#endif