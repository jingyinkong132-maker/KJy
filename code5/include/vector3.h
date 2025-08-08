#ifndef VECTOR3F_H
#define VECTOR3F_H

// 三维向量结构体
typedef struct {
    float x;
    float y;
    float z;
} vector3f;

// 向量加法
vector3f vec_add(vector3f a, vector3f b);

// 向量减法
vector3f vec_sub(vector3f a, vector3f b);

// 点乘
float vec_dot(vector3f a, vector3f b);

// 求模长
float vec_length(vector3f v);

// 单位化
vector3f vec_normalize(vector3f v);

// 叉乘
vector3f vec_cross(vector3f a, vector3f b);

#endif
