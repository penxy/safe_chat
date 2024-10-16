# ThreadPool
```cpp
#include "ThreadPool.h"
ThreadPool pool(8);
    std::vector<std::future<int>> results;

    for(int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool.enqueue([i] {
                std::cout << "hello " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "world " << i << std::endl;
                return i*i;
            })
        );
    }

    for(auto && result: results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;
```

# LZ4
```cpp
#include "LZ4/lz4file.h"
/**
 * @brief 压缩文件
 */
#include ""
static int compress_file(FILE* f_in, FILE* f_out) {
    const int CHUNK_SIZE = 16 * 1024;
    LZ4F_errorCode_t ret = LZ4F_OK_NoError;
    size_t len;
    LZ4_writeFile_t* lz4fWrite;
    void* const buf = malloc(CHUNK_SIZE);
    if (!buf) {
        printf("error: memory allocation failed \n");
        return 1;
    }

    ret = LZ4F_writeOpen(&lz4fWrite, f_out, NULL);
    if (LZ4F_isError(ret)) {
        free(buf);
        return 1;
    }

    while (1) {
        len = fread(buf, 1, CHUNK_SIZE, f_in);

        if (ferror(f_in)) {
            printf("fread error\n");
            goto out;
        }

        /* nothing to read */
        if (len == 0) {
            break;
        }

        ret = LZ4F_write(lz4fWrite, buf, len);
        if (LZ4F_isError(ret)) {
            //printf("LZ4F_write: %s\n", LZ4F_getErrorName(ret));
            goto out;
        }
    }

out:
    free(buf);
    if (LZ4F_isError(LZ4F_writeClose(lz4fWrite))) {
        return 1;
    }

    return 0;
}
/**
 * @brief 解压文件
 */
static int decompress_file(FILE* f_in, FILE* f_out) {
    LZ4F_errorCode_t ret = LZ4F_OK_NoError;
    LZ4_readFile_t* lz4fRead;
    void* const buf= malloc(CHUNK_SIZE);
    if (!buf) {
        printf("error: memory allocation failed \n");
    }

    ret = LZ4F_readOpen(&lz4fRead, f_in);
    if (LZ4F_isError(ret)) {
        free(buf);
        return 1;
    }

    while (1) {
        ret = LZ4F_read(lz4fRead, buf, CHUNK_SIZE);
        if (LZ4F_isError(ret)) {
            goto out;
        }

        /* nothing to read */
        if (ret == 0) {
            break;
        }

        if(fwrite(buf, 1, ret, f_out) != ret) {
            //printf("write error!\n");
            goto out;
        }
    }

out:
    free(buf);
    if (LZ4F_isError(LZ4F_readClose(lz4fRead))) {
        return 1;
    }

    if (ret) {
        return 1;
    }

    return 0;
}

/**
 * @brief compare two files
 * @retval true if files are equal
 */
bool compareFiles(FILE* fp0, FILE* fp1) {
    bool result = 0;
    while (!result) {
        char b0[1024];
        char b1[1024];
        size_t const r0 = fread(b0, 1, sizeof(b0), fp0);
        size_t const r1 = fread(b1, 1, sizeof(b1), fp1);

        result = (r0 != r1);
        if (!r0 || !r1) break;
        if (!result) result = memcmp(b0, b1, r0);
    }
    return result;
}
```
# gmssl
```cpp
#include "gmssl/sm4.h"
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
```
