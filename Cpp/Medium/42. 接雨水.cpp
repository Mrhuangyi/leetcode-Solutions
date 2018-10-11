/*

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

*/

//
//  test3.cpp
//  test2
//
//  Created by a on 2018/10/11.
//  Copyright © 2018 a. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int trap(vector<int>& height) {
    const int n = height.size();
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(height[i] > height[max]) {
            max = i;
        }
    }
    int water = 0;
    for(int i = 0, peak = 0; i < max; i++) {
        if(height[i] > peak) {
            peak = height[i];
        } else {
            water += peak - height[i];
        }
    }
    for(int i = n - 1, top = 0; i > max; i--) {
        if(height[i] > top) {
            top = height[i];
        } else {
            water += top - height[i];
        }
    }
    return water;
}

int main()
{
    vector<int> height(12, 0);
    for(int i = 0; i < height.size(); i++) {
        scanf("%d", &height[i]);
    }
    int result = trap(height);
    printf("%d \n", result);
    return 0;
}

