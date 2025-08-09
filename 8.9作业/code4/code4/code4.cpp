// code4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// 比较函数：用于 qsort，升序排序
int compare(const void* a, const void* b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    if (fa < fb) return -1; // fa 在 fb 前
    else if (fa > fb) return 1; // fa 在 fb 后
    else return 0; // 相等
}

int main() {
    float* arr = NULL; // 动态数组
    int count = 0;     // 已输入的个数
    float temp;

    cout<<"请输入任意数量的浮点数（输入非数字结束输入）：\n";

    // 动态读取输入
    while (cin >> temp) {  // 输入成功时为 true，失败时为 false
        float* newArr = (float*)realloc(arr, (count + 1) * sizeof(float));
        if (!newArr) {
            cout << "内存分配失败！\n";
            free(arr);
            return 1;
        }
        arr = newArr;
        arr[count++] = temp;
    }

    if (count == 0) {
        cout<<"没有输入任何数字。\n";
        free(arr);
        return 0;
    }

    // 使用 qsort 排序
    qsort(arr, count, sizeof(float), compare);

    // 输出结果
    cout<<"从小到大的排序结果：\n";
    for (int i = 0; i < count; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    // 释放内存
    free(arr);
    return 0;
}
