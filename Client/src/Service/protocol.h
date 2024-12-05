#pragma once

#include <QObject>
#include <memory>
#include <QJsonObject>
#include <QTcpSocket>
#include "const_json.h"

class Core;
class NetCore;

/**
 * @class Protocol
 * @brief 生成json并发送，接收json并解析
 */
class Protocol : public QObject, public std::enable_shared_from_this<Protocol>{
    Q_OBJECT
public:
    Protocol(QObject *parent);
    ~Protocol();
public:
    void init(std::shared_ptr<Core>core, const char *host, int port);
    void create_and_send(TypeJson::Send type, void *data);                                    //由core调用
private:
    bool send();
    void createHead();
private slots:
    void onReadyRead();
private: 
    std::shared_ptr<Core> m_core;                                   //解析json后，调用Core的接口

    struct Hand{
        int index = 0;                                              //协议序号
        QString account_id;                                         //发送者id
        TypeJson::Send type;                                        //协议类型
        QString recv_id;                                            //接收者id
        //时间
        QString public_key;                                         //公钥
    }m_hand;

    QTcpSocket m_socket;
    QString recv_text;
    QJsonObject m_json;
};