#ifndef __MY_SM4_H__
#define __MY_SM4_H__

#include "gmssl/sm4.h"
#include "gmssl/hex.h"
class __DEBUG_SM4_T {
public:
    __DEBUG_SM4_T(const std::string& key_str, const std::string& iv_str) {
        const size_t key_str_size = key_str.size();
        uint8_t* key = (uint8_t*)malloc(key_str_size >> 1);//除以2, 原因未知
        size_t key_size;
        hex_to_bytes(key_str.c_str(), key_str.size(), key, &key_size);

        size_t iv_str_size = iv_str.size();
        init_iv = (uint8_t* )malloc((iv_str_size + 1) >> 1);
        hex_to_bytes(iv_str.c_str(), iv_str_size, init_iv, &iv_size);

        enc_key = new SM4_KEY();
        dec_key = new SM4_KEY();
        sm4_set_encrypt_key(enc_key, key);
        sm4_set_decrypt_key(dec_key, key);
    }
    ~__DEBUG_SM4_T(){
        delete enc_key;
        delete dec_key;
    }
public:
    std::string my_encrypt(const std::string& str){
        const size_t in_str_size = str.size();
        uint8_t* in = (uint8_t* )malloc(in_str_size);
        for(size_t i = 0; i < in_str_size; i++){
            in[i] = (int)str[i];
        }

        uint8_t* iv = (uint8_t* )malloc(iv_size);
        memcpy(iv, init_iv, iv_size);
        uint8_t out[in_str_size];
        sm4_cbc_encrypt_blocks(enc_key, iv, in, (str.size() / 16), out);

        std::string encrypt = "";
        for(size_t i = 0; i < in_str_size; i++){
            encrypt.push_back(out[i]);
        }
        free(in);
        //free(iv);会导致错误

        return encrypt;
    }
    std::string my_decrypt(const std::string& str){
        const size_t in_str_size = str.size();
        uint8_t* in = (uint8_t* )malloc(in_str_size);
        for(size_t i = 0; i < str.size(); i++){
            in[i] = (int)str[i];
        }
        
        uint8_t* iv = (uint8_t* )malloc(iv_size);
        memcpy(iv, init_iv, iv_size);
        uint8_t ans[in_str_size];
        
        sm4_cbc_decrypt_blocks(dec_key, iv, in, (str.size() / 16), ans);

        std::string decrypt = "";
        for(size_t i = 0; i < in_str_size; i++){
            decrypt += ans[i];
        }

        free(in);
        free(iv);
        return decrypt;
    }
private:
    uint8_t* init_iv;
    size_t iv_size;
    SM4_KEY *enc_key;
    SM4_KEY *dec_key;
};

#endif
