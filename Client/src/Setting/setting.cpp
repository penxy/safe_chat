#include "setting.h"

Setting::Setting() : ISystemSetting(), QObject(){

}
Setting::~Setting() {
    
}

QString& Setting::getUser() {
    return m_user;
}
QString& Setting::getPassword() {
    return m_password;
}
QString& Setting::getIpFtp() {
    return m_ip_ftp;
}
QString& Setting::getKey() {
    return m_key;
}
QString& Setting::getIv() {
    return m_iv;
}
QString& Setting::getDb() {
    return m_db;
}
