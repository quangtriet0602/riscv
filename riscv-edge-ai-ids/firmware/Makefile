# ==========================================
# Makefile cho Firmware RISC-V (Vigenere Cipher)
# Tác giả: Triết Dương Quang (Đại diện Kỹ thuật số)
# ==========================================

CXX = riscv-none-elf-g++
CFLAGS = -O3 -march=rv32imac -mabi=ilp32 -ffreestanding -nostdlib

all: main.cpp vigenere.cpp
	$(CXX) $(CFLAGS) main.cpp -o test.elf
	@echo "Đã biên dịch thành công tệp nhị phân cho RISC-V!"

clean:
	rm -f *.elf *.o