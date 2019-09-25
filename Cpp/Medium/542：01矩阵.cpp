给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
       int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) q.push({i, j});
                else matrix[i][j] = INT_MAX;
            }
        }
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            for (auto dir : dirs) {
                int x = t.first + dir[0], y = t.second + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[t.first][t.second] + 1) continue;
                matrix[x][y] = matrix[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
        return matrix;

    }
};
