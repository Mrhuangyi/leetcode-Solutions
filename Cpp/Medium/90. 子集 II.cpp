给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) {
            return res;
        }
        sort(nums.begin(), nums.end());
        res.push_back(vector<int>());
        vector<int> v;
        generate(0, v, nums);
        return res;
    }
    void generate(int start, vector<int>& v, vector<int>& nums) {
        if(start == nums.size()) {
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            v.push_back(nums[i]);
            res.push_back(v);
            generate(i + 1, v, nums);
            v.pop_back();
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }
};
