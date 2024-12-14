#include "core_setting.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>
#include <QDebug>
#include "args.h"
/*
{
    user="pxy",
    password="16759",
    ip_ftp="192.168.64.132",
    key="adsfadsfasmfasfsafhcasmfkasjfasf",
    iv="adsfasmfasfsadsfasmfasfsafhcafhc",
    db_name="release/Linux/etc/main.db",
    db_script="release/Linux/etc/sql_script.sql"
}
*/

CoreSetting::CoreSetting() : ISystemSetting(), QObject(){
    std::string path = FLAGS_base + "/etc/client.conf";
    QFile file(path.c_str());
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray all_data = file.readAll();
        file.close();

        QJsonParseError json_error;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(all_data, &json_error));
        if(json_error.error != QJsonParseError::NoError){
            qDebug() << QString("Error: %1").arg(json_error.errorString());
            return;
        }

        QJsonObject root_json = jsonDoc.object();
        m_user = root_json["user"].toString();
        m_password = root_json["password"].toString();
        m_ip_ftp = root_json["ip_ftp"].toString();
        m_key = root_json["key"].toString();
        m_iv = root_json["iv"].toString();
        m_db_name = root_json["db_name"].toString();
        m_db_script = root_json["db_script"].toString();
    }else{
        qDebug() << "client.js open Error";
    }
}
CoreSetting::~CoreSetting() {
    
}

QString& CoreSetting::getUser() {
    return m_user;
}
QString& CoreSetting::getPassword() {
    return m_password;
}
QString& CoreSetting::getIpFtp() {
    return m_ip_ftp;
}
QString& CoreSetting::getKey() {
    return m_key;
}
QString& CoreSetting::getIv() {
    return m_iv;
}
QString& CoreSetting::getDbName() {
    return m_db_name;
}
QString& CoreSetting::getDbScript(){
    return m_db_script;
}