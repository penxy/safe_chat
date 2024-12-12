#pragma once
#include <QString>
/*
user="pxy"
password="16759"
ip_ftp="192.168.64.132"
key="adsfadsfasmfasfsafhcasmfkasjfasf"
iv="adsfasmfasfsadsfasmfasfsafhcafhc"
db="release/Linux/etc/main.db"

*/

/**
 * @class ISystemSetting
 * @brief 系统设置
 */
class ISystemSetting{
public:
    ISystemSetting() = default;
    ~ISystemSetting() = default;

    virtual QString& getUser() = 0;
    virtual QString& getPassword() = 0;
    virtual QString& getIpFtp() = 0;
    virtual QString& getKey() = 0;
    virtual QString& getIv() = 0;
    virtual QString& getDb() = 0;
protected:
    QString m_user;
    QString m_password;
    QString m_ip_ftp;
    QString m_key;
    QString m_iv;
    QString m_db;
};