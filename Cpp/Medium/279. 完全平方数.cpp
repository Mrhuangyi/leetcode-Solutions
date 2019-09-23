给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.


DP写法：

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 1; i + j * j <= n; j++) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};

BFS写法：

class Solution {
public:
    int numSquares(int n) {
        int splitNum = 0;
        q.push({n, 0});
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            int num = current.first;
            for (int i = 1; i <= sqrt(n); ++i) {
                int next = num - pow(i, 2);
                if (next < 0) {
                    break;
                }
                if (next == 0) {
                    return current.second + 1;
                }
                q.push({next, current.second + 1});
            }
        }
        return splitNum;
    }
private:
    queue<pair<int, int> > q;
};
