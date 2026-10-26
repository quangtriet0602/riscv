#include "vigenere.cpp"

// Giả lập cổng UART hoặc thanh ghi xuất dữ liệu trên vi điều khiển RISC-V tùy chỉnh
volatile uint32_t* const UART_TX = (volatile uint32_t*) 0x40000000;

void print_uart(const char* str) {
    while (*str) {
        *UART_TX = (uint32_t)(*str++);
    }
}
//hàm mới
inline uint32_t strlen(const char* str) {
    uint32_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
int main() {
    const char* secret_key = "RISCV";
    const char* original_text = "Hello Triet, testing Vigenere encryption on hardware core!";
    uint32_t text_len = strlen(original_text);

    char ciphertext[128];
    char decryptedtext[128];

    VigenereCipher cipher(secret_key);

    // Thực thi mã hóa
    cipher.encrypt(original_text, ciphertext, text_len);
    
    // Thực thi giải mã kiểm tra tính đúng đắn
    cipher.decrypt(ciphertext, decryptedtext, text_len);

    print_uart("Ciphertext: ");
    print_uart(ciphertext);
    print_uart("\n");

    print_uart("Decrypted: ");
    print_uart(decryptedtext);
    print_uart("\n");

    // Vòng lặp vô hạn kết thúc chương trình bare-metal
    while (1) {
        // Chờ tín hiệu hoặc ngắt
    }
    return 0;
}