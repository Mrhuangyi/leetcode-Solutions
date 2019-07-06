给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        建立map表用于存储每个连续子数组sum求和出现的次数，初始化为（0,1），表示和为0的连续子数组出现1次。

        sum的值是在对nums数组的循环中不断累加当前元素的，res的值则需要查找map中是否已存在sum-k的元素，也就是在查         找此前所有从0项开始累加的连续子项和中有没有sum-k。

        如果有的话，则说明从该项到当前项的连续子数组和必定为k，那么res则可以和这个sum的对应值，即这个sum出现的次           数，相加得到新的res。

        对于当前sum如果已存在与map中则其对应值+1，不存在则添加新项，初始值为1。
        */
        int sum = 0, res = 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res += hash[sum - k];
            ++hash[sum];
        }
        return res;
    }
};

