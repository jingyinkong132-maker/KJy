// float-score.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
using namespace std;


int main() {
    float a = 3.14, b = -2.71;
    char buf[8]; 
    int i;

    cout << "请选择存取方法 (1=memcpy, 2=指针, 3=整数存储): ";
    cin >> i;

    if (i == 1) {
        // 方法 1: memcpy
        memcpy(buf, &a, sizeof(float));
        memcpy(buf + sizeof(float), &b, sizeof(float));
    }
    else if (i == 2) {
        // 方法 2: 指针类型转换
        *(float*)(buf) = a;
        *(float*)(buf + sizeof(float)) = b;
    }
    else if (i == 3) {
        // 方法 3: 转整数存储
        uint32_t a_bits, b_bits;
        memcpy(&a_bits, &a, 4);
        memcpy(&b_bits, &b, 4);
        ((uint32_t*)buf)[0] = a_bits;
        ((uint32_t*)buf)[1] = b_bits;
    }
    else {
        cout << "无效的选择！" << endl;
        return 1;
    }

    // 还原
    float a1, b1;
    memcpy(&a1, buf, 4);
    memcpy(&b1, buf + 4, 4);

    // 输出
    cout << "原值 : a = " << a << ", b = " << b << endl;
    cout << "还原 : a1 = " << a1 << ", b1 = " << b1 << endl;
    cout << "差值 : Δa = " << (a - a1) << ", Δb = " << (b - b1) << endl;

    return 0;
}

