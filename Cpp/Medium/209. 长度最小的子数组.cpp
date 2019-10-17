/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
*/

双指针法：
时间复杂度O(n)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, sum = 0, len = nums.size();
        int res = INT_MAX;
        if(len == 0) {
            return 0;
        }
        for(int i = 0; i < len; i++) {
            sum += nums[i];
            while(sum >= s) {
                res = min(res, i - left + 1);
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
        
    }
};


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        while(right < len) {
            while(sum < s && right < len) {
                sum += nums[right++];
            }
            while(sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == len + 1 ? 0 : res;
    }
};



二分查找
时间复杂度O(nlogn)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), sums[len + 1] = {0}, res = len + 1;
        for(int i = 1; i < len + 1; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for(int i = 0; i < len + 1; i++) {
            int right = searchRight(i + 1, len, sums[i] + s, sums);
            if(right == len + 1) {
                break;
            }
            if(res > right - i) {
                res = right - i;
            }
        }
        return res == len + 1 ? 0 : res;
    }
    int searchRight(int left, int right, int key, int sums[]) {
        while(left <= right) {
            int mid = (left + right) / 2;
            if(sums[mid] >= key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
