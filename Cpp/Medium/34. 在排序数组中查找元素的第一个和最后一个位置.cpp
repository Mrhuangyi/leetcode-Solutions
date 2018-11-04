/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

法一：直接遍历数组，但是时间复杂度为O(n),并不符合要求

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1, right = -1;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                left = i;  
                res.push_back(left);
                break;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] == target) {
                right = i;
                res.push_back(right);
                break;
            }
        }
        if(left == -1 && right == -1) {
            res.push_back(left);
        res.push_back(right);
        }
        return res;
    }
};

法二：二分查找  
时间复杂度为(logn).


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int leftIdx = binarySearch(nums, target, true);
        if(leftIdx == nums.size() || nums[leftIdx] != target) {
            return res;
        }
        res[0] = leftIdx;
        res[1] = binarySearch(nums, target, false) - 1;
        return res;
    }
    int binarySearch(vector<int> nums, int target, bool left) {
        int low = 0;
        int high = nums.size();
        while(low < high) {
            int mid = (low + high) / 2;
            if(nums[mid] > target || (left && target == nums[mid])) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
