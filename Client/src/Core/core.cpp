#include "core.h"
#include <qmetatype.h>//qRegisterMetaType
#include "config.h"
#include <unistd.h>

#include "curl/curl.h"


/**
 * @def Core
 * @todo 随机生成公钥和id, 以及注册各种信号传递的类型[such as qRegisterMetaType<Type::Json>("Type::Json");]
 */
Core::Core(std::shared_ptr<Protocol>protocol) : QObject(), CoreFd(), CoreGp(), CoreSelf(), CoreRecore(), m_protocol(protocol){
}

//fd
/**
 * @def Core::sendFriend
 * @note 所有的Friend, Group都是在这里构建的, args要么第一个参数是下标，要么前几个参数都是构建它们的参数
 */
bool Core::sendFriend(TypeJson::Send type_send, std::array<QVariant, 4>args){
    switch(type_send){
        case TypeJson::Send::FdAccept: {//std::shared_ptr<Friend>
            ChatId id = args.at(0).value<ChatId>();
            QString pix_base64 = args.at(1).value<QString>();
            QString name = args.at(2).value<QString>();
            auto f = std::make_shared<Friend>(id, pix_base64, name);
            m_fd_list.push_back(f->shared_from_this());
            emit SigUpdateListFd(); //update.
            break;
        }   
        default:{
            break;
        }
    }
    return true;
}
void Core::recvFriend(TypeJson::Recv type_recv, std::array<QVariant, 4>args){}

std::shared_ptr<Friend>& Core::getFriend(int idx){auto _f = std::make_shared<Friend>(); return _f;}
QList<std::shared_ptr<Friend>>& Core::getFriendList(){
    return m_fd_list;
}

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

//Ftp
void Core::upLoadFile(const QString& file_name){
    CURL *curl = curl_easy_init();
    FILE *file = fopen(file_name.toStdString().c_str(), "r");
    // FILE* curl_log = fopen("debug.log", "wb");
    curl_easy_setopt(curl, CURLOPT_USERPWD, "pxy:16759");

    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);//设置显示信息
    // curl_easy_setopt(curl, CURLOPT_STDERR, (void*)curl_log);
    curl_easy_setopt(curl, CURLOPT_URL, "ftp://192.168.64.132/temp");//暂时固定
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_READDATA, (void*)file);
    CURLcode ret = curl_easy_perform(curl);
    // if (ret == CURLE_OK) {
    //     std::cout << "OK\n";
    // }
    // else {
    //     std::cout << "error\n";
    // }
    //C:\Users\srcty\Desktop\music.txt
    curl_easy_cleanup(curl);
    fclose(file);
    // fclose(curl_log);
}
static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream){
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
void Core::downLoadFile(const QString& file_name){
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_USERPWD, "pxy:16759");
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);//设置显示信息
    FILE *file = fopen(file_name.toStdString().c_str(), "wb");
    
    curl_easy_setopt(curl, CURLOPT_URL, "ftp://192.168.64.132/temp");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    CURLcode ret = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    fclose(file);
}