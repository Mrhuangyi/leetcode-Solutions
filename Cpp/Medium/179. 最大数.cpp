/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/

class Solution {
public:
    bool static cmp(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int>& nums) {
        string res;
        
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }
        if(res[0] == '0') {
            return "0";
        } else {
        return res;
    }
    }
};
