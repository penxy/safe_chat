#include "C_Conf.h"
#include "hv/iniparser.h"

#include <assert.h>
#include <unistd.h>

void C_Conf::init(const std::string& path_conf){
    IniParser* parser = new IniParser();

    int ret = parser->LoadFromFile(path_conf.c_str());
    assert(access(path_conf.c_str(), F_OK) == 0);
    
    m_user = parser->GetValue("user");
    m_pwd = parser->GetValue("password");
    m_ip_ftp = parser->GetValue("ip_ftp");
    m_key = parser->GetValue("key");
    m_iv = parser->GetValue("iv");
}