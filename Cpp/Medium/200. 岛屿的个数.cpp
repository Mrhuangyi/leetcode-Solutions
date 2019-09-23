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

DFS写法：

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

BFS写法：

class Solution {
private:
    queue<int> que;
    int count = 0;
    int x = 0;
    int y = 0;
    int xx = 0;
    int yy = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = row > 0 ? grid[0].size() : 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        if(row == 0 || col == 0) {
            return 0;
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1') {
                    que.push(i);
                    que.push(j);
                    grid[i][j] = '0';
                    while(!que.empty()) {
                        x = que.front();
                        que.pop();
                        y = que.front();
                        que.pop();
                        for(int k = 0; k < 4; k++) {
                            xx = x + dx[k];
                            yy = y + dy[k];
                            if(xx < 0 || xx >= row || yy < 0 || yy >= col) {
                                continue;
                            }
                            if(grid[xx][yy] == '1' ) {
                                grid[xx][yy] = '0';
                                que.push(xx);
                                que.push(yy);
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};
