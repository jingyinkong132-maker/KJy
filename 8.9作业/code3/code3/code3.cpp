// code3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// code3_fixed.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

typedef struct MParam {
    uint8_t row;
    uint8_t column;
    float** data;
} *Matrix;
// 创建矩阵，分配内存
Matrix create(uint8_t row, uint8_t column) {
    Matrix m = (Matrix)malloc(sizeof(struct MParam));
    if (!m) { 
        cout << "内存分配失败\n"; return NULL; 
    }
    m->row = row;
    m->column = column;
    // 分配行指针
    m->data = (float**)malloc(row * sizeof(float*));
    if (!m->data) { 
        cout << "内存分配失败\n"; free(m); return NULL; 
    }
    // 分配每一行的数据空间
    for (int i = 0; i < row; i++) {
        m->data[i] = (float*)malloc(column * sizeof(float));
        if (!m->data[i]) {
            cout << "内存分配失败\n";
            for (int j = 0; j < i; j++) free(m->data[j]);
            free(m->data); free(m);
            return NULL;
        }
    }
    return m;
}
// 释放矩阵内存
void freeMatrix(Matrix m) {
    if (!m) return;
    for (int i = 0; i < m->row; i++) free(m->data[i]);
    free(m->data);
    free(m);
}
// 输入矩阵数据
void input(Matrix m) {
    printf("请输入矩阵元素（共 %d 行 %d 列）：\n", (int)m->row, (int)m->column);
    for (int i = 0; i < m->row; i++)
        for (int j = 0; j < m->column; j++)
            cin >> m->data[i][j];
}
// 输出矩阵
void output(Matrix m) {
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->column; j++) printf("%8.2f ", m->data[i][j]);
        printf("\n");
    }
}
// 矩阵转置
Matrix transpose(Matrix m) {
    Matrix t = create(m->column, m->row);
    if (!t) return NULL;
    for (int i = 0; i < m->row; i++)
        for (int j = 0; j < m->column; j++)
            t->data[j][i] = m->data[i][j];
    return t;
}
// 矩阵乘法
Matrix multiply(Matrix a, Matrix b) {
    if (a->column != b->row) { cout<<"矩阵维度不匹配，无法相乘！\n"; return NULL; }
    Matrix c = create(a->row, b->column);
    if (!c) return NULL;
    for (int i = 0; i < c->row; i++)
        for (int j = 0; j < c->column; j++) {
            c->data[i][j] = 0.0f;
            for (int k = 0; k < a->column; k++) c->data[i][j] += a->data[i][k] * b->data[k][j];
        }
    return c;
}

int main() {
    int row, column;           
    cout << "请输入矩阵行数: ";
    cin >> row;
    cout << "请输入矩阵列数: ";
    cin >> column;

 
    uint8_t row = (uint8_t)row;
    uint8_t column = (uint8_t)column;

    Matrix m = create(row, column);
    if (!m) return -1;

    input(m);
    cout << "输入的矩阵是：\n"; output(m);

    Matrix t = transpose(m);
    if (!t) { freeMatrix(m); return -1; }
    cout << "矩阵的转置是：\n"; output(t);

    Matrix prod = multiply(m, t);
    if (!prod) { freeMatrix(m); freeMatrix(t); return -1; }
    cout << "矩阵与其转置的乘积是：\n"; output(prod);

    freeMatrix(m); freeMatrix(t); freeMatrix(prod);
    return 0;
}
