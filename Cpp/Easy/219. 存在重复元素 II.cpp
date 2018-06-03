给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> check;
        for(int i=0;i<nums.size();i++){
            if(check.find(nums[i])==check.end()){
                check[nums[i]]=i;
            }else{
                if(i-check[nums[i]]<=k){
                    return true;
                }
                check[nums[i]]=i;
            }
        }
        return false;
    }
};
