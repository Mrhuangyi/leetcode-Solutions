给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size() == 0 || target < 0) {
            return res;
        }
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        BackTracking(res, curr, candidates, target, 0);
        return res;
    }
    void BackTracking(vector<vector<int>>& res, vector<int> curr, vector<int> candidates, int target, int level) {
        if(target == 0) {
            res.push_back(curr);
            return;
        } else if(target < 0) {
            return;
        }
        for(int i = level; i < candidates.size(); i++) {
            target -= candidates[i];
            curr.push_back(candidates[i]);
            BackTracking(res, curr, candidates, target, i);
            curr.pop_back();
            target += candidates[i];
        }
    }
};
