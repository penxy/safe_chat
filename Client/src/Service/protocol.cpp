#include "protocol.h"
#include "Core/core.h"
#include "const_json.h"

#include <QTcpSocket>
#include <QJsonArray>
#include <QDateTime>
#include <QJsonDocument>

/**
 * @namespace JsonHand
 * @brief     包含json头部的属性
 */
namespace JsonHand{
    const QString index{"index"};                                              //协议序号
    const QString account_id{"account_id"};                                    //发送者id
    const QString time{"time"};                                                //发送时间
    const QString type{"type"};                                                //消息类型
    const QString recv_id{"recv_id"};                                          //接收者id
    const QString content{"content"};                                          //消息内容
    const QString public_key{"public_key"};                                    //公钥
}

Protocol::Protocol(QObject *parent) : QObject(parent){}
Protocol::~Protocol(){}
/**
 * @def init
 * @param[in] core 核心
 * @param[in] account_id 账号id
 * @param[in] host 服务器地址
 * @param[in] port 服务器端口
 * @brief 初始化网络
 */
void Protocol::init(std::shared_ptr<Core>core, const char *host, int port){
    m_core = core;
    m_hand.account_id = m_core->getId().toString();
    m_hand.public_key = m_core->getPublicKey();

    m_socket.connectToHost(QString::fromStdString(host), port);
    connect(&m_socket, &QTcpSocket::readyRead, this, &Protocol::onReadyRead);
}




/**
 * @def createHead
 * @brief 创建消息头, 由create_and_send调用
 */
void Protocol::createHead(){
    m_json = QJsonObject();
    m_json.insert(JsonHand::index, m_hand.index);
    m_json.insert(JsonHand::account_id, m_hand.account_id);
    m_json.insert(JsonHand::time, QDateTime::currentDateTime().toString());
    m_json.insert(JsonHand::type, static_cast<uint8_t>(m_hand.type));
    m_json.insert(JsonHand::recv_id, m_hand.recv_id);
    m_json.insert(JsonHand::public_key, m_hand.public_key);
}

/**
 * @def send
 * @param[in] msg 发送的消息
 * @brief 发送消息, 由create_and_send函数调用
 */
bool Protocol::send(){
    if(!m_socket.isValid())return false;
    
    //QJson -> QString -> QByteArray
    QJsonDocument doc(m_json);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    const QByteArray send_data = strJson.toUtf8();
    
    m_socket.write(send_data);
}

/**
 * @def onReadyRead
 * @brief 收到数据了，处理m_core
 */
void Protocol::onReadyRead(){
    if(m_socket.bytesAvailable() <= 0) return;
    QString recv_text = QString::fromUtf8(m_socket.readAll());
    //处理json,判断类型，解析分配参数，调用Core::recvGroup/Core::recvFriend
}