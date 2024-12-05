#pragma once
#include "config.h"
#include <QWidget>
class TitleBtn;

class TitleBar : public QWidget{
    Q_OBJECT
public:
    TitleBar(QWidget *parent = nullptr);
private:
    void onClicked();
private:
    TitleBtn *m_btn_min;
    TitleBtn *m_btn_max;  //it will be changed to restore button when the window is maximized
    TitleBtn *m_btn_close;
};