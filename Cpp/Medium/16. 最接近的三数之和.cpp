/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() <= 2) {
            return -1;
        }
        int res = 0;
        int distance = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int tempVal = nums[i] + nums[j] + nums[k];
                int tempDis;
                if(tempVal < target) {
                    tempDis = target - tempVal;
                    if(tempDis < distance) {
                        distance = tempDis;
                        res = nums[i] + nums[j] + nums[k];
                    }
                    ++j;
                } else if(tempVal > target) {
                    tempDis = tempVal - target;
                    if(tempDis < distance) {
                        distance = tempDis;
                        res = nums[i] + nums[j] + nums[k];
                    }
                    --k;
                } else {
                    res = nums[i] + nums[j] + nums[k];
                    return res;
                }
            } 
        }
        return res;
    }
};
