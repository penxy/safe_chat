#include "Layout.h"

Layout::Layout(QBoxLayout::Direction direction, QWidget *parent) : QBoxLayout(direction, parent){
    this->setContentsMargins(0, 0, 0, 0);
    this->setAlignment(Qt::AlignVCenter);
}

    
