给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

    
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int len = nums.size();
        vector<int> dp(len);
        for(int i = 0; i < len; i++) {
            dp[i] = 1;
        }
        int maxLen = 1;
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > maxLen) {
                maxLen = dp[i];
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        vector<int> res(nums.size(),1);
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                //后面的元素比前面的元素值大，那么后面的元素可以放在前面的元素后面形成一个新的子序列
                if(nums[i] > nums[j]) {
                    //更新记录的长度值
                    res[i] = max(res[i], res[j] + 1);
                }
            }
        }
        int len = 1;
        for(int i = 0; i < res.size(); i++) {
            len = max(len, res[i]);
        }
        return len;
    }
};
