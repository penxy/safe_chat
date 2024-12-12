#include "friend.h"
#include "utils/tool.h"

/*
void setHistory(const QList<ns::History>& history) override;
    QList<ns::History>& getHistory() override;

*/
Friend::Friend(){}
Friend::Friend(const ChatId& id, const QString& pix_base64, const QString& name) : m_chat_id(id), m_name(name){
    m_pix.loadFromData(QByteArray::fromBase64(pix_base64.toUtf8()));
    


}
Friend& Friend::operator=(const Friend& other){
    if(this == &other) return *this;
    m_chat_id = other.m_chat_id;
    m_name = other.m_name;
    m_pix = other.m_pix;
    return *this;
}
Friend::Friend(const Friend& other){
    *this = other;
}

void Friend::setPix(const QPixmap& pix){
    if(TOOL.pix2Base64(m_pix) != TOOL.pix2Base64(pix)){
        m_pix = pix;
        emit SigPixChanged(m_pix);
    }
}
void Friend::setName(const QString& name){
    if(!setVal(m_name, name)){
        emit SigNameChanged(m_name);
    }
}
void Friend::setHistory(const QList<ns::History>& history){
    m_history = history;
}
ChatId& Friend::getId(){
    return m_chat_id;
}
QPixmap& Friend::getPix(){
    return m_pix;
}
QString& Friend::getName(){
    return m_name;
}
QList<ns::History>& Friend::getHistory(){
    return m_history;
}

template <typename T> bool Friend::setVal(T& savedVal, T newVal){
    if(savedVal != newVal){
        savedVal = newVal;
        return true;
    } return false;
}