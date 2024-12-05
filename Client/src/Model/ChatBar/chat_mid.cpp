#include "chat_mid.h"
#include <QDateTime>
#include <QVBoxLayout>

ChatMid::ChatMid(QWidget *parent) : QWidget(parent){
    this->resize(sz::chat_mid_wid_base);

    QVBoxLayout* layout_main = new QVBoxLayout(this);
    layout_main->addWidget(&m_list_widget);

    QString qss = R"(
        //my.qss
        QListWidget
        {
            border:1px solid gray;   /*边界线:宽度、颜色*/
            /*background:gray;*/    /*表格背景色*/
            color:black;        /*前景色：文字颜色*/
            /*margin:5px,5px,0px,50px;*/   /*上、下、左、右，间距*/
        }
        
        /*
        QListWidget::item
        {
            padding-top:24px;
            padding-bottom:4px;
        }
        */
        
        QListWidget::item:hover
        {
            show-decoration-selected:5;
            background:skyblue;
        }
        
        QListWidget::item:selected
        {
            /*border:0px;*/
            background:lightgray;
            padding:0px;
            margin:0px;
            color:red;
        }
        
        /*上次选择后保留的状态，鼠标离开后显示*/
        QListWidget::item:selected:!active
        {
            border-width:0px;
            background:lightgreen;
        }
        
        
        /*QTableWidget*/
        QTableWidget
        {
            color:green;    /*前景色：文字颜色*/
            /*gridline-color:red;   */     /*表格中的网格线条颜色*/
            background:white;
            /*设置交替颜色，需要在函数属性中设置:tableWidget->setAlternatingRowColors(true)*/
            /*alternate-background-color:red;   */
            selection-color:red;    /*鼠标选中时前景色：文字颜色*/
            selection-background-color:lightgray;   /*鼠标选中时背景色*/
            border:1px solid gray;  /*边框线的宽度、颜色*/
            /*border:none;*/    /*去除边界线*/
            /*border-radius:5px;*/
            /*padding:10px 10px;*/  /*表格与边框的间距*/
        }
        
        /*设置表头属性*/
        QTableWidget QHeaderView::section
        {
            background-color:#F0F0F0;  /*lightgray*/
            /*color:black;*/
            /*padding-left:4px;*/
            /*border:3px solid red;*/   /*表头边框线的宽度、颜色*/
            /*border:1px solid gray;*/
        }
    )";
    //this->setStyleSheet(qss);
}


void ChatMid::dealMessageTime(QString curMsgTime)
{
    bool isShowTime = false;
    if(m_list_widget.count() > 0) {
        QListWidgetItem* lastItem = m_list_widget.item(m_list_widget.count() - 1);
        BubbleMsg* messageW = (BubbleMsg*)m_list_widget.itemWidget(lastItem);
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
    } else {
        isShowTime = true;
    }
    if(isShowTime) {
        BubbleMsg* messageTime = new BubbleMsg(m_list_widget.parentWidget());
        QListWidgetItem* itemTime = new QListWidgetItem(&m_list_widget);

        QSize size = QSize(this->width(), 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, curMsgTime, size, BubbleMsg::User_Time);
        m_list_widget.setItemWidget(itemTime, messageTime);
    }
}

void ChatMid::dealMessage(BubbleMsg *messageW, QListWidgetItem *item, QString text, QString time,  BubbleMsg::User_Type type)
{
    messageW->setFixedWidth(this->width());
    QSize size = messageW->fontRect(text);
    item->setSizeHint(size);
    messageW->setText(text, time, size, type);
    m_list_widget.setItemWidget(item, messageW);
}



// void Widget::on_pushButton_clicked()
// {
//     QString msg = m_edit->text();
//     m_edit->clear();
//     QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
//     bool isSending = false; // 发送中

//     dealMessageTime(time);
//     m_widget_msg_vec.push_back(new WidgetMsg(m_list_widget->parentWidget()));
//     QListWidgetItem* item = new QListWidgetItem(m_list_widget);
//     dealMessage(m_widget_msg_vec.back(), item, msg, time, WidgetMsg::User_Me);
//     if(isSending == true) {
//         m_widget_msg_vec.back()->setTextSuccess();
//     }
// }

void ChatMid::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event);
    for(int i = 0; i < m_list_widget.count(); i++) {
        BubbleMsg* messageW = (BubbleMsg*)m_list_widget.itemWidget(m_list_widget.item(i));
        QListWidgetItem* item = m_list_widget.item(i);
        dealMessage(messageW, item, messageW->text(), messageW->time(), messageW->userType());
    }
}


void ChatMid::SlotSendMsg(const QString &msg){
    QString time = QString::number(QDateTime::currentDateTime().toTime_t());
    bool isSending = false; // 发送中

    dealMessageTime(time);
    m_widget_msg_vec.push_back(new BubbleMsg(m_list_widget.parentWidget()));
    QListWidgetItem* item = new QListWidgetItem(&m_list_widget);
    dealMessage(m_widget_msg_vec.back(), item, msg, time, BubbleMsg::User_Me);
    if(isSending == true) {
        m_widget_msg_vec.back()->setTextSuccess();
    }
}