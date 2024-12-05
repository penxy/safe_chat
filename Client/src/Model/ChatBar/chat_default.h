#pragma once

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

/**
 * @class ChatDefault
 * @brief 右侧聊天栏默认界面
 */
class ChatDefault : public QWidget{
public:
    ChatDefault(QWidget *parent = nullptr){
        QLabel *main_label = new QLabel;
        main_label->setPixmap(QPixmap(":/Icons/MainWindow/chat.png"));
        QHBoxLayout *layout_main = new QHBoxLayout(this);
        layout_main->addWidget(main_label);
        layout_main->setAlignment(Qt::AlignCenter);
        layout_main->setContentsMargins(0, 0, 0, 0);

        this->setStyleSheet("border:none;");
    }
};