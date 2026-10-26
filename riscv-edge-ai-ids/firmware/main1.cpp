/**
 * ==========================================
 * 2. TẦNG PHẦN SỤN SUY LUẬN (C++ Firmware)
 * ==========================================
 * Chạy trực tiếp trên RISC-V không qua hệ điều hành.
 * Gọi phần cứng như một hàm/driver hệ thống.
 */
#include <iostream>
#include "../models/weights_export.h"

// Giả lập giao tiếp phần cứng qua địa chỉ MMIO
#define HARDWARE_ACCELERATOR_BASE 0x80000000

void invoke_hardware_accelerator(int* input_data) {
    volatile int* hw_reg = (volatile int*)HARDWARE_ACCELERATOR_BASE;
    // Gửi dữ liệu xuống mạch phần cứng xử lý song song
    *hw_reg = *input_data;
}

int main() {
    std::cout << ">>> RISC-V Bare-metal AI Inference Started <<<" << std::endl;
    int sample_input = 42;
    invoke_hardware_accelerator(&sample_input);
    std::cout << ">>> Suy luận hoàn tất tại biên. <<<" << std::endl;
    return 0;
}
