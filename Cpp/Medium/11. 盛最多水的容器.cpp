/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
*/

//
//  maxArea11.cpp
//  LeetCode
//
//  Created by a on 2018/10/25.
//  Copyright © 2018 Leetcode. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height) {
    //时间复杂度O(n^2),空间复杂度O(1)
    int maxarea = 0;
    for(int i = 0; i < height.size(); i++) {
        for(int j = 0; j < height.size(); j++) {
            maxarea = max(maxarea, min(height[i], height[j]) * (j - i));
        }
    }
    return maxarea;
}
int maxArea2(vector<int>& height) {
    //时间复杂度O(n),空间复杂度O(1)
    int maxarea = 0;
    int left = 0;
    int right = height.size() - 1;
    while(left < right) {
        maxarea = max(maxarea, min(height[left], height[right] )* (right - left));;
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxarea;
    
}
int main()
{
    vector<int> height;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        height.push_back(x);
    }
    int maxarea1 = maxArea(height);
    int maxarea2 = maxArea2(height);
    cout<< maxarea1 << " " << maxarea2 << endl;
    return 0;
}
