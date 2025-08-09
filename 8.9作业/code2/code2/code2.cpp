// code2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
using namespace std;

int main() {
    float f1 = 59.622f;
    float f2 = 92.6327f;

    int scale = 100;

    uint16_t i1 = static_cast<uint16_t>(f1 * scale + 0.5f); 
    uint16_t i2 = static_cast<uint16_t>(f2 * scale + 0.5f);
//先将浮点数乘以100放大成整数，再加0.5做四舍五入,转为无符号16位整数 uint16_t.
  
    cout << "Original floats: " << f1 << ", " << f2 <<endl;

    cout << "Scaled integers: " << i1 << ", " << i2 <<endl;

    uint32_t combined = (static_cast<uint32_t>(i1) << 16) | i2;

    char arr[4];
    memcpy(arr, &combined, 4);

    uint32_t extracted;
    memcpy(&extracted, arr, 4);

    uint16_t ei1 = (extracted >> 16) & 0xFFFF;
    uint16_t ei2 = extracted & 0xFFFF;

    float rf1 = static_cast<float>(ei1) / scale;
    float rf2 = static_cast<float>(ei2) / scale;

    
    cout << "Recovered floats: " << rf1 << ", " << rf2 << endl;

    
    cout << "Errors: " << f1 - rf1 << ", " << f2 - rf2 ;

    return 0;
}