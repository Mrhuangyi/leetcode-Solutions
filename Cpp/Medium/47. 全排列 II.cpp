给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) {
            return res;
        }
        vector<int> curr;
        vector<bool> isVisited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(res, curr, nums, isVisited);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int> curr, vector<int> nums, vector<bool> isVisited) {
        if(curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(isVisited[i] == false) {
                isVisited[i] = true;
                curr.push_back(nums[i]);
                dfs(res, curr, nums, isVisited);
                isVisited[i] = false;
                curr.pop_back();
                while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    ++i;
                }
            }
        }
    }
};
