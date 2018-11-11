/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int right = n - 1;
        int left = 0;
        int top = 0;
        int bottom = n - 1;
        int count = 1;
        while(count <= n * n) {
            for(int i = left; i <= right; i++) {
                res[top][i] = count++;
            }
            top++;
            for(int j = top; j <= bottom; j++) {
                res[j][right] = count++;
            }
            right--;
            for(int i = right; i >= left; i--) {
                res[bottom][i] = count++;
            }
            bottom--;
            for(int j = bottom; j >= top; j--) {
                res[j][left] = count++;
            }
            left++;
        }
        return res;
    }
};
