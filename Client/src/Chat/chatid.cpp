#include "chatid.h"

// ChatId(const QString &id);
// ChatId(const QByteArray &id);

ChatId::ChatId(const QByteArray &id) : m_id(id){

}
ChatId::ChatId(const QString &id){
    m_id = id.toUtf8();
}
ChatId& ChatId::operator = (const ChatId &other){
    m_id = other.m_id;
    return *this;
}
bool ChatId::operator == (const ChatId& other) const{
    return m_id == other.m_id;
}
bool ChatId::operator != (const ChatId& other) const{
    return m_id != other.m_id;
}
bool ChatId::operator < (const ChatId& other) const
{
    return m_id < other.m_id;
}
QString ChatId::toString() const
{
    return QString::fromUtf8(m_id.toHex()).toUpper();
}
QByteArray ChatId::getByteArray() const{
    return m_id;
}
std::unique_ptr<ChatId> ChatId::clone(){
    return std::unique_ptr<ChatId>(new ChatId(*this));
}
