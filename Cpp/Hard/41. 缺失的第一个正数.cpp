/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/
思路一：用集合。我们把给定数组的正整数都插入到集合里，并且在插入的同时记录最大值。之后从1开始遍历到最大值，若遍历到某个值是该值在集合中不存在，就返回该值，如果都存在，那么最后返回最大值+1.这种解法并不满足常熟级别的空间。
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        int maxNum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0) {
                continue;
            }
            s.insert(nums[i]);
            maxNum = max(maxNum, nums[i]);
        }
        for(int i = 1; i <= maxNum; i++) {
            if(!s.count(i)) {
                return i;
            }
        }
        return maxNum + 1;
    }
};

思路二：原地改变数组。
我们能不能想办法让nums[i]所表示的值为i+1，这样的话之后遍历数组，只需要找到与下标不符的位置即可。那么如何让nums[i]的值为i+1呢？我们遍历给定数组，当发现nums[i]>0,nums[i]<=n,并且nums[nums[i]-1]!=nums[i]的时候，我们用while循环交换nums[nums[i]-1]和nums[i],直到位置正确。你们看看这一步效果是什么。

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
