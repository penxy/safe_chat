#include "group.h"
#include "utils/tool.h"

Group::Group(const ChatId& id, const QString& pix_base64, const QString& name) : m_chat_id(id), m_name(name){
    m_pix.loadFromData(QByteArray::fromBase64(pix_base64.toUtf8()));
    


}
Group& Group::operator=(const Group& other){
    if(this == &other) return *this;
    m_chat_id = other.m_chat_id;
    m_name = other.m_name;
    m_pix = other.m_pix;
    return *this;
}
Group::Group(const Group& other){
    *this = other;
}
void Group::setPix(const QPixmap& pix){
    if(TOOL.pix2Base64(m_pix) != TOOL.pix2Base64(pix)){
        m_pix = pix;
        emit SigPixChanged(m_pix);
    }
}
void Group::setName(const QString& name){
    if(!setVal(m_name, name)){
        emit SigNameChanged(m_name);
    }
}
void Group::setHistory(const QList<ns::History>& history){
    m_history = history;
}

ChatId& Group::getId(){
    return m_chat_id;
}
QPixmap& Group::getPix(){
    return m_pix;
}
QString& Group::getName(){
    return m_name;
}
QList<ns::History>& Group::getHistory(){
    return m_history;
}

template <typename T> bool Group::setVal(T& savedVal, T newVal){
    if(savedVal != newVal){
        savedVal = newVal;
        return true;
    } return false;
}
