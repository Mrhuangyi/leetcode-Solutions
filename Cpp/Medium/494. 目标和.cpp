给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组非空，且长度不会超过20。
初始的数组的和不会超过1000。
保证返回的最终结果能被32位整数存下。

一：dp解法

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int a = sum * 2 + 1;
        if(S >= a || S + sum >= a) {
            return 0;
        }
        vector<int> dp(a);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * 2;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=a-1;j>=nums[i];j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[sum+S]; 
    }
};

二：DFS
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        int sum = 0;
        dfs(nums, S, count, 0, sum);
        return count;
    }
private:
   void dfs(vector<int>& nums, int S, int& count, int counter, int sum)
    {
        if(counter == nums.size())
        {
            if(sum == S)
                ++ count;
            return;
        }
        //counter = counter + 1;
        dfs(nums, S, count, counter + 1, sum + nums[counter]);
        dfs(nums, S, count, counter + 1, sum -  nums[counter]);
    }
};
