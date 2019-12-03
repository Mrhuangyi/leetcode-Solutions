给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

//hash解法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int i = 0; i < nums.size(); i++) {
            if(hashSet.count(nums[i]) > 0) {
                hashSet.erase(nums[i]);
            } else {
            hashSet.insert(nums[i]);
            }
        }
        int res;
        for(auto a : hashSet) {
            res = a;
        }
        return res;
    }
};

//异或解法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        return x;
    }
};
