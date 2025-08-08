#include <stdio.h>
#include <math.h>
#include "../include/vector3.h"

// 计算点到直线的距离
float point_to_line_distance(vector3f point, vector3f line_point, vector3f line_dir) {
    vector3f diff = vec_sub(point, line_point);
    vector3f cross = vec_cross(diff, line_dir);
    float distance = vec_length(cross) / vec_length(line_dir);
    return distance;
}

// 计算直线到平面的距离（直线必须平行于平面）
float line_to_plane_distance(vector3f line_point, vector3f plane_point, vector3f plane_normal) {
    vector3f diff = vec_sub(line_point, plane_point);
    float distance = fabs(vec_dot(diff, plane_normal)) / vec_length(plane_normal);
    return distance;
}

int main() {
    // 正方体棱长为1，建立坐标系
    // 假设A在原点(0,0,0)，B在(1,0,0)，D在(0,1,0)，A1在(0,0,1)等
    
    // (1) 求点B到直线AC1的距离
    vector3f A = {1, 0, 1};
    vector3f B = {1, 1, 1};
    vector3f C1 = {0, 1, 0};
    
    vector3f AC1_dir = vec_sub(C1, A);  // AC1的方向向量
    float distance1 = point_to_line_distance(B, A, AC1_dir);
    printf("(1) 点B到直线AC1的距离: %.4f\n", distance1);
    
    // (2) 求直线FC到平面AEC1的距离
    vector3f F = {1, 0.5, 1};  // AB的中点
    vector3f C = {0, 1, 1};
    vector3f E = {1, 0.5, 0};  // A1B1的中点
    vector3f FC_dir = vec_sub(C, F);  // FC的方向向量
    
    // 计算平面AEC1的法向量
    vector3f AE = vec_sub(E, A);
    vector3f AC1 = vec_sub(C1, A);
    vector3f plane_normal = vec_cross(AE, AC1);
    
    // 检查FC是否平行于平面（点积为0）
    if (fabs(vec_dot(FC_dir, plane_normal)) < 1e-6) {
        // 取FC上任意一点（如F）到平面的距离
        float distance2 = line_to_plane_distance(F, A, plane_normal);
        printf("(2) 直线FC到平面AEC1的距离: %.4f\n", distance2);
    } else {
        printf("(2) 直线FC与平面AEC1不平行，无法计算距离\n");
    }
    
    return 0;
}