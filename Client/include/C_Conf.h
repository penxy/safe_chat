#ifndef __C_CONF_H__
#define __C_CONF_H__

#include "Tool/single_model.h"
#include <string>

class C_Conf : public Singleton<C_Conf> {
    friend class Singleton<C_Conf>;
public:
    C_Conf (const C_Conf&) = delete;
    C_Conf& operator = (const C_Conf&) = delete;
protected:
    C_Conf() = default;

public:
    void init(const std::string& path_conf);
    std::string& get_user();
    std::string& get_pwd();
    std::string& get_key();
    std::string& get_iv();
    std::string& get_ip_ftp();
private:
    std::string m_user;
    std::string m_pwd;

    std::string m_key;
    std::string m_iv;

    std::string m_ip_ftp;
};




#endif // !__C_CONF_H__