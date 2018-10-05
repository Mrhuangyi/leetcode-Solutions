/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() <= 2) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                vector<int> curr;
                if(nums[i] + nums[j] + nums[k] == 0) {
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    curr.push_back(nums[k]);
                    res.push_back(curr);
                    ++j;
                    --k;
                    while(j < k && nums[j - 1] == nums[j]) {
                        ++j;
                    }
                    while(j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                } else if(nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return res;
    }
};
