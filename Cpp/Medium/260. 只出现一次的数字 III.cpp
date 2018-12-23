/*
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]
注意：

结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] != nums[i + 1]) {
                res.push_back(nums[i]);
                i++;
            } else {
                i += 2;
            }
        }
        if(res.size() == 1) {
            res.push_back(nums.back());
        }
        return res;
    }
};
