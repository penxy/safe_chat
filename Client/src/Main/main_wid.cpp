#include "main_wid.h"

MainWid::MainWid(QMainWindow *parent) : WidBase(parent){
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setCentralWidget(&m_main_wid);
}
