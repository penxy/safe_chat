#include "wid_base.h"

WidBase::WidBase(QMainWindow *parent) : QMainWindow(parent){

}
void WidBase::mousePressEvent(QMouseEvent *event)
{
    if( (event->button() == Qt::LeftButton) ){
        mouse_press = true;
        mousePoint = event->globalPos() - this->pos();
    }
}
void WidBase::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
        move(event->globalPos() - mousePoint);
}
void WidBase::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}

