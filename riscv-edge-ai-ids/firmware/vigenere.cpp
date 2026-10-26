#include <stdint.h>

class VigenereCipher {
private:
    const char* key;
    uint32_t key_len;

    inline uint8_t get_offset(char c) const {
        if (c >= 'A' && c <= 'Z') return c - 'A';
        if (c >= 'a' && c <= 'z') return c - 'a';
        return 0;
    }

public:
    // 1. Constructor nhận 1 tham số (tự động tính độ dài chuỗi khóa thủ công, không cần strlen)
    VigenereCipher(const char* k) : key(k) {
        key_len = 0;
        while (k[key_len] != '\0') {
            key_len++;
        }
    }

    // 2. Constructor nhận 2 tham số (khóa và độ dài tường minh)
    VigenereCipher(const char* k, uint32_t k_len) : key(k), key_len(k_len) {}

    void encrypt(const char* plaintext, char* ciphertext, uint32_t len) {
        uint32_t key_index = 0;
        for (uint32_t i = 0; i < len; i++) {
            char p = plaintext[i];
            if (p >= 'A' && p <= 'Z') {
                char k = key[key_index % key_len];
                uint8_t shift = get_offset(k);
                ciphertext[i] = 'A' + (p - 'A' + shift) % 26;
                key_index++;
            } 
            else if (p >= 'a' && p <= 'z') {
                char k = key[key_index % key_len];
                uint8_t shift = get_offset(k);
                ciphertext[i] = 'a' + (p - 'a' + shift) % 26;
                key_index++;
            } 
            else {
                ciphertext[i] = p;
            }
        }
        ciphertext[len] = '\0';
    }

    void decrypt(const char* ciphertext, char* plaintext, uint32_t len) {
        uint32_t key_index = 0;
        for (uint32_t i = 0; i < len; i++) {
            char c = ciphertext[i];
            if (c >= 'A' && c <= 'Z') {
                char k = key[key_index % key_len];
                uint8_t shift = get_offset(k);
                plaintext[i] = 'A' + (c - 'A' - shift + 26) % 26;
                key_index++;
            } 
            else if (c >= 'a' && c <= 'z') {
                char k = key[key_index % key_len];
                uint8_t shift = get_offset(k);
                plaintext[i] = 'a' + (c - 'a' - shift + 26) % 26;
                key_index++;
            } 
            else {
                plaintext[i] = c;
            }
        }
        plaintext[len] = '\0';
    }
};