/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
private: 
    void solveNQueens(vector<vector<string>> &res, vector<string> &nQueens, int row, int n) {
        if(row == n) {
            res.push_back(nQueens);
            return;
        }
        for(int col = 0; col != n; col++) {
            if(isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string> &nQueens, int row, int col, int &n) {
        for(int i = 0; i < row; i++) {
            if(nQueens[i][col] == 'Q') {
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));
        vector<int> flag_col(n, 1);
        vector<int> flag_45(2 * n - 1, 1);
        vector<int> flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string>> &res, vector<string> &nQueens, vector<int> &flag_col, vector<int> &flag_45, vector<int> &flag_135, int row, int &n) {
        if(row == n) {
            res.push_back(nQueens);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
            nQueens[row][col] = 'Q';
            solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
            nQueens[row][col] = '.';
            flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
        }
    }
};
