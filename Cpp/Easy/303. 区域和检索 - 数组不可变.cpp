给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:

你可以假设数组不可变。
会多次调用 sumRange 方法。


class NumArray {
public:
    NumArray(vector<int> nums) {
        dp.resize(nums.size()+1,0);
        for(int i=1;i<=nums.size();++i){
            dp[i] = dp[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1]-dp[i];
    }
    private: 
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
