#pragma once

#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
class MyFrame : public QFrame{
public:
    MyFrame(QHBoxLayout *layout = nullptr, QWidget *parent = nullptr) : QFrame(parent) {
        this->setFrameShape(QFrame::Box);
        this->setFrameShadow(QFrame::Sunken);
        this->setLineWidth(2);
        this->setLayout(layout);
    }
    MyFrame(QVBoxLayout *layout = nullptr, QWidget *parent = nullptr) : QFrame(parent) {
        this->setFrameShape(QFrame::Box);
        this->setFrameShadow(QFrame::Sunken);
        this->setLineWidth(2);
        this->setLayout(layout);
    }
};