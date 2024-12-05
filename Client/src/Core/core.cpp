#include "core.h"
#include <qmetatype.h>//qRegisterMetaType
#include "config.h"
/**
 * @def Core
 * @todo 随机生成公钥和id, 以及注册各种信号传递的类型[such as qRegisterMetaType<Type::Json>("Type::Json");]
 */
Core::Core(std::shared_ptr<Protocol>protocol) : QObject(), CoreFd(), CoreGp(), CoreSelf(), CoreRecore(), m_protocol(protocol){
    qRegisterMetaType<Type::Identity>("Type::Identity");  
}

//fd
bool Core::sendFriend(TypeJson::Send type_send, std::array<QVariant, 4>args){return true;}
void Core::recvFriend(TypeJson::Recv type_recv, std::array<QVariant, 4>args){}

std::shared_ptr<Friend>& Core::getFriend(int idx){auto _f = std::make_shared<Friend>(); return _f;}
QList<std::shared_ptr<Friend>>& Core::getFriendList(){QList<std::shared_ptr<Friend>> _f;return _f;}

ChatId& Core::getFriendId(int idx){ChatId id = ChatId();return id;}
std::string& Core::getFriendName(int idx){std::string s;return s;}
QPixmap& Core::getFriendPhoto(int idx){QPixmap p;return p;}
//gp
bool Core::sendGroup(TypeJson::Send type_send, std::array<QVariant, 4>args){return true;}
void Core::recvGroup(TypeJson::Recv type_recv, std::array<QVariant, 4>args){}

std::shared_ptr<Group>& Core::getGroup(int idx){auto _f = std::make_shared<Group>(); return _f;}
QList<std::shared_ptr<Group>>& Core::getGroupList(){QList<std::shared_ptr<Group>> _f;return _f;}

ChatId& Core::getGroupId(int idx){ChatId id = ChatId();return id;}
std::string& Core::getGroupName(int idx){std::string s;return s;}
QPixmap& Core::getGroupPhoto(int idx){QPixmap p;return p;}
//self
bool Core::setPass(const QString& pass){return true;}
bool Core::setName(const QString& name){return true;}
bool Core::setStatus(const Type::Status& status){}

ChatId& Core::getId(){return m_id;}
QString& Core::getName(){return m_name; }
Type::Status& Core::getStatus(){return m_status;}
QString& Core::getPublicKey() {return m_publicKey;}

//Recore
void Core::loadGroupRecore(int idx){}
void Core::saveGroupRecore(int idx){}
void Core::loadFriendRecore(int idx){}
void Core::saveFriendRecore(int idx){}

