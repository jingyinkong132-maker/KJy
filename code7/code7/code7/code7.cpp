// code7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <stdint.h>

using namespace std;

uint32_t swap_endian(uint32_t val) {
    return ((val >> 24) & 0xFF) |
        ((val >> 8) & 0xFF00) |
        ((val << 8) & 0xFF0000) |
        ((val << 24) & 0xFF000000);
}

int main() {
    uint32_t num = 0x12253647;

    // 判断本机字节序
    uint16_t test = 0x1;
    bool is_little = *(uint8_t*)&test == 1;

    cout << "本机字节序: " << (is_little ? "小端" : "大端") << "模式" << endl;

    cout << "原始: 0x" << hex << uppercase << num << endl;

    cout << "小端: 0x" << hex << uppercase
        << (is_little ? num : swap_endian(num)) << endl;

    cout << "大端: 0x" << hex << uppercase
        << (is_little ? swap_endian(num) : num) << endl;

    return 0;
}