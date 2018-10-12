/*

给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/

//
//  rotate_image.cpp
//  Leetcode
//
//  Created by a on 2018/10/12.
//  Copyright © 2018 Leetcode. All rights reserved.
//

#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
int n;
// 时间复杂度O(n^2),空间复杂度O(1)
void rotate1(vector<vector<int>>& matrix) {
    //const int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) { // 沿着副对角线反转
            swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
        }
    }
    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n; j++) { // 沿着水平线反转
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}
// 时间复杂度O(n^2),空间复杂度O(1)
void rotate2(vector<vector<int>>& matrix) {
    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n; j++) { // 沿着水平线反转
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) { // 沿着主对角线反转
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
int main()
{
    
    while(~scanf("%d", &n)) {
        vector<vector<int> > matrix(n);
        for(int i = 0; i < n; i++) {
            matrix[i].resize(n);
        }
        int x;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &x);
                matrix[i][j] = x;
            }
        }
        rotate1(matrix);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d",matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
