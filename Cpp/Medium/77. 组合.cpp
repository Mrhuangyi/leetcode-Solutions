给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n <= 0) {
            return res;
        }
        vector<int> curr;
        dfs(res, curr, n, k, 1);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int> curr, int n, int k, int level) {
        if(curr.size() == k) {
            res.push_back(curr);
            return ;
        }
        if(curr.size() > k) {
            return;
        }
        for(int i = level; i <= n; i++) {
            curr.push_back(i);
            dfs(res, curr, n, k, i + 1);
            curr.pop_back();
        }
    }
};
