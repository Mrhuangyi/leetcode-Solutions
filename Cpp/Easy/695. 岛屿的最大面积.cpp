给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

用dfs或bfs搜索遍历二维数组。

深度优先搜索借助递归，沿着某找路径往下直到结束。

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int res = 0;
        vector<vector<bool>> mark(grid.size(), vector<bool>(grid[0].size(), false));
        int deep = grid.size();
        int len = grid[0].size();
        for(int i = 0; i < deep; i++) {
            for(int j = 0; j < len; j++) {
                if(mark[i][j]) {
                    continue;
                }
                int temp = dfs(grid, i, j, mark);
                res = max(res, temp);
            }
        }
        return res;
    }
private:
    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& mark) {
        if(x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0) {
            return 0;
        }
        if(mark[x][y]) {
            return 0;
        }
        if(grid[x][y] == 0) {
            return 0;
        } 
        mark[x][y] = true;
        return 1 + dfs(grid, x + 1, y, mark) + dfs(grid, x - 1, y, mark) + dfs(grid, x, y + 1, mark) + dfs(grid, x, y - 1, mark);
    }
};

bfs需要借助栈进行一层层遍历搜索。

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int res = 0;
        vector<vector<bool>> mark(grid.size(), vector<bool>(grid[0].size(), false));
        int deep = grid.size();
        int len = grid[0].size();
        for(int i = 0; i < deep; i++) {
            for(int j = 0; j < len; j++) {
                if(mark[i][j]) {
                    continue;
                }
                if(grid[i][j] == 0) {
                    continue;
                }
                int temp = 0;
                stack<pair<int, int>> st;
                st.push(make_pair(i, j));
                mark[i][j] = true;
                while(!st.empty()) {
                    temp++;
                    pair<int, int> cur = st.top();
                    st.pop();
                    int x = cur.first;
                    int y = cur.second;
                    if(x - 1 >= 0 && grid[x - 1][y] == 1 && mark[x - 1][y] == false) {
                        st.push(make_pair(x - 1, y));
                        mark[x - 1][y] = true;
                    }
                    if(x + 1 < deep && grid[x + 1][y] == 1 && mark[x + 1][y] == false) {
                        st.push(make_pair(x + 1, y));
                        mark[x + 1][y] = true;
                    }
                    if(y - 1 >= 0 && grid[x][y - 1] == 1 && mark[x][y - 1] == false) {
                        st.push(make_pair(x, y - 1));
                        mark[x][y - 1] = true;
                    }
                    if(y + 1 < len && grid[x][y + 1] == 1 && mark[x][y + 1] == false) {
                        st.push(make_pair(x, y + 1));
                        mark[x][y + 1] = true;
                    }
                }
                res = max(res, temp);
            }
        }
        return res;
    }
};
