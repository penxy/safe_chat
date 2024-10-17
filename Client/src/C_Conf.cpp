#include "C_Conf.h"
#include <assert.h>

void C_Conf::init(const std::string& path_conf){
    conf_ctx_t* m_ctx = new conf_ctx_t();

    m_ctx->parser = new IniParser;
    int ret = m_ctx->parser->LoadFromFile(path_conf.c_str());
    assert(access(path_conf.c_str(), F_OK) == 0);
    
    m_user = m_ctx->parser->GetValue("user");
    m_pwd = m_ctx->parser->GetValue("password");
    m_ip_ftp = m_ctx->parser->GetValue("ip_ftp");
    m_key = m_ctx->parser->GetValue("key");
    m_iv = m_ctx->parser->GetValue("iv");
}