// code6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


using namespace std;

int main() {
    uint32_t result = 0;          
    srand(static_cast<unsigned>(time(NULL))); // 用当前时间做随机种子

    for (int i = 0; i < 32; i++) {
        int num = rand() % 101;   // 生成0~100范围内随机整数
        cout << "第" << i + 1 << "个数=" << num << " -> ";

        if (num > 50) {
            result |= (1U << i);  // 如果大于50，将 result 的第 i 位设为1（最低位为第1位）
            cout << "位值=1" << endl;
        }
        else {
            cout << "位值=0" << endl;
        }
    }

    cout << "最终整数: " << result << endl;


    return 0;
}