/*
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for(int i = 0; i < nums.size(); i++) {
            int k = i;
            string s = to_string(nums[i]);
            while(nums[i]  + 1 == nums[i + 1] && i + 1 < nums.size()) {
                i++;
            }
            if(k != i) {
                s += "->" + to_string(nums[i]);
                res.push_back(s);
                continue;
            }
            res.push_back(s);
        }
        return res;
    }
};
