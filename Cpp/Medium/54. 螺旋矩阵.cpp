/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

*/



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
         if(matrix.size() == 0) {
            return res;
        }
        int row1 = 0;
        int row2 = matrix.size() - 1;
        int col1 = 0;
        int col2 = matrix[0].size() - 1;
       
        while(row1 <= row2 && col1 <= col2) {
            for(int i = col1; i <= col2; i++) {
                res.push_back(matrix[row1][i]);
            }
            for(int i = row1 + 1; i <= row2; i++) {
                res.push_back(matrix[i][col2]);
            }
            if(row1 != row2) {
                for(int i = col2 - 1; i >= col1; i--) {
                    res.push_back(matrix[row2][i]);
                }
            }
            if(col1 != col2) {
                for(int i = row2 - 1; i > row1; i--) {
                    res.push_back(matrix[i][col1]);
                }
            }
            row1++;
            row2--;
            col1++;
            col2--;
        }
        return res;
    }
};



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) {
            return {};
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
        while(true) {
            for(int col = l; col <= r; col++) {
                res[k++] = matrix[u][col];
            }
            if(++u > d) {
                break;
            }
            for(int row = u; row <= d; row++) {
                res[k++] = matrix[row][r];
            }
            if(--r < l) {
                break;
            }
            for(int col = r; col >= l; col--) {
                res[k++] = matrix[d][col];
            }
            if(--d < u) {
                break;
            }
            for(int row = d; row >= u; row--) {
                res[k++] = matrix[row][l];
            }
            if(++l > r) {
                break;
            }
        }
        return res;
    }
};
