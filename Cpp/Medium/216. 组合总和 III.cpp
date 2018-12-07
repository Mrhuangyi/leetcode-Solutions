/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(k, n, 1, out, res);
        return res;
    }
    void dfs(int k, int n, int level, vector<int> &out, vector<vector<int>> &res) {
        if(n < 0) {
            return;
        }
        if(n == 0 && out.size() == k) {
            res.push_back(out);
        }
        for(int i = level; i <= 9; ++i) {
            out.push_back(i);
            dfs(k, n - i, i + 1, out, res);
            out.pop_back();
        }
    }
};
