给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int flag = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == flag) {
                cnt++;
            } else {
                cnt--;
            }
            if(cnt == 0) {
                cnt = 1;
                flag = nums[i];
            }
        }
        return flag;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};
