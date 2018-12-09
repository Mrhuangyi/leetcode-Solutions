/*
给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

示例 1:

输入: [3,2,3]
输出: [3]
示例 2:

输入: [1,1,1,3,3,2,2,2]
输出: [1,2]

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        vector<int> res;
        int num1, num2, cnt1 = 0, cnt2 = 0, len = nums.size();
        for(auto val : nums) {
            if(num1 == val) {
                cnt1++;
            } else if(num2 == val) {
                cnt2++;
            } else if(cnt1 == 0) {
                cnt1 = 1, num1 = val;
            } else if(cnt2 == 0) {
                cnt2 = 1, num2 = val;
            } else {
                cnt1--, cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(auto val : nums) {
            if(val == num1) {
                cnt1++;
            } else if(val == num2) {
                cnt2++;
            }
        }
        if(cnt1 > len / 3.0) {
            res.push_back(num1);
        }
        if(cnt2 > len / 3.0) {
            res.push_back(num2);
        }
        return res;
    }
};
