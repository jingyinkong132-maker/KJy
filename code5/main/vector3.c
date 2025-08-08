#include "../include/vector3.h"
#include <math.h> // sqrtf

// 向量加法
vector3f vec_add(vector3f a, vector3f b) {
    return (vector3f){a.x + b.x, a.y + b.y, a.z + b.z};
}

// 向量减法
vector3f vec_sub(vector3f a, vector3f b) {
    return (vector3f){a.x - b.x, a.y - b.y, a.z - b.z};
}

// 点乘
float vec_dot(vector3f a, vector3f b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

// 求模长
float vec_length(vector3f v) {
    return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}

// 单位化
vector3f vec_normalize(vector3f v) {
    float len = vec_length(v);
    return len == 0 ? v : (vector3f){v.x/len, v.y/len, v.z/len};
}

// 叉乘
vector3f vec_cross(vector3f a, vector3f b) {
    return (vector3f){
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - a.y*b.x
    };
}
