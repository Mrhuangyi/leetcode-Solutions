/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:

输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

class Solution {
public:
    int sum;
    int totalNQueens(int n) {
        vector<int> col(n);
        sum = 0;
        dfs(n, 0, col);
        return sum;
    }
    bool isValid(int row, int col, vector<int> &cols) {
        for(int i = 0; i < row; i++) {
            if(cols[i] - i == col - row) {
                return false;
            }
            if(cols[i] + i == col + row) {
                return false;
            }
            if(cols[i] == col) {
                return false;
            }
        }
        return true;
    }
    void dfs(int n, int k, vector<int> &cols) {
        if(k == n) {
            sum++;
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!isValid(k, i, cols)) {
                continue;
            }
            cols[k] = i;
            dfs(n, k + 1, cols);
        }
    }
};
