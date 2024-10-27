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

# list
```C
struct person
{
    struct list_head list;
    int age;
};

int main(int argc,char **argv)
{
    struct person *p;
    struct person person1;
    struct list_head *pos;

    INIT_LIST_HEAD(&person1.list);

    for (int i = 0;i < 5;i++) {
        p = (struct person *)malloc(sizeof(struct person ));
        p->age=i*10;
        list_add(&p->list,&person1.list);
    }

    list_for_each(pos, &person1.list) {
        printf("age = %d\n",((struct person *)pos)->age);
    }

    return 0;
}
```

# Curl
```C

CURL *curl = curl_easy_init();
FILE *file = fopen("C:/Users/srcty/Desktop/Demo/s.py", "r");
FILE* curl_log = fopen("debug.log", "wb");

curl_easy_setopt(curl, CURLOPT_USERPWD, "pxy:16759");

curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);//设置显示信息
curl_easy_setopt(curl, CURLOPT_STDERR, (void*)curl_log);

curl_easy_setopt(curl, CURLOPT_URL, "ftp://192.168.64.132/s.py");
curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
curl_easy_setopt(curl, CURLOPT_READDATA, (void*)file);

CURLcode ret = curl_easy_perform(curl);
if (ret == CURLE_OK) {
    std::cout << "OK\n";
}
else {
    std::cout << "error\n";
}

curl_easy_cleanup(curl);
fclose(file);
fclose(curl_log);

```


# cryptopp
```cpp
#include <cryptopp/cryptlib.h>
#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
#include <cryptopp/base64.h>

std::string encrypt(const std::string& input, const std::vector<uint8_t>& key, const std::vector<uint8_t>& iv) {
    std::string cipher;
    
    auto aes = CryptoPP::AES::Encryption(key.data(), key.size());
    auto aes_cbc = CryptoPP::CBC_Mode_ExternalCipher::Encryption(aes, iv.data());
    
    CryptoPP::StringSource ss(
        input, 
        true, 
        new CryptoPP::StreamTransformationFilter(
            aes_cbc, 
            new CryptoPP::Base64Encoder(
                new CryptoPP::StringSink(cipher)
            )
        )
    );

    return cipher;
}

std::string decrypt(const std::string& cipher_text, const std::vector<uint8_t>& key, const std::vector<uint8_t>& iv) {
    std::string plain_text;
    
    auto aes = CryptoPP::AES::Decryption(key.data(), key.size());
    auto aes_cbc = CryptoPP::CBC_Mode_ExternalCipher::Decryption(aes, iv.data());
    
    CryptoPP::StringSource ss(
        cipher_text, 
        true, 
        new CryptoPP::Base64Decoder(
            new CryptoPP::StreamTransformationFilter(
                aes_cbc, 
                new CryptoPP::StringSink(plain_text)
            )
        )
    );

    return plain_text;
}


int main(int argc,char **argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);
    C_Conf::get_inst().init(FLAGS_confile);

   static constexpr size_t AES_KEY_SIZE = 256 / 8; //AES-256

    const std::string input {"This is a secret message."};
    std::vector<uint8_t> key(AES_KEY_SIZE);
    std::vector<uint8_t> iv(CryptoPP::AES::BLOCKSIZE);

    CryptoPP::BlockingRng rand;
    rand.GenerateBlock(key.data(), key.size());
    rand.GenerateBlock(iv.data(), iv.size());

    auto cipher = encrypt(input, key, iv);
    auto plain_text = decrypt(cipher, key, iv);

    if(plain_text != input) {
        std::cout << "Error: plain text doesn't match the input" << std::endl;
    }

    return 0;
}



```