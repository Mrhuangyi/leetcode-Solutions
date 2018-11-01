/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 
![alt](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/histogram.png)


以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 
![alt](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/histogram_area.png)


图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int res = 0;
        for(int i = 0; i < heights.size(); ) {
            if(s.empty() || heights[i] > heights[s.top()]) {
                s.push(i++);
            } else {
                int temp = s.top();
                s.pop();
                res = max(res, heights[temp] * (s.empty() ? i: i - s.top() - 1));
            }
        }
        return res;
    }
};
