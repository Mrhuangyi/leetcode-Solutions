/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3

*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res += grid[i][j] - '0';
                dfs(grid, j, i, m, n);
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, int j, int i, int m, int n) {
        if(j < 0 || i < 0 || j >= n || i >= m || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, j + 1, i, m, n);
        dfs(grid, j - 1, i, m, n);
        dfs(grid, j, i + 1, m, n);
        dfs(grid, j, i - 1, m, n);
    }
};
