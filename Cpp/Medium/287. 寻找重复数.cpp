给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2

示例 2:

输入: [3,1,3,4,2]
输出: 3

说明：

不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。


class Solution {
public:
    /**
        快慢指针思想, fast 和 slow 是指针, nums[slow] 表示取指针对应的元素
        注意 nums 数组中的数字都是在 1 到 n 之间的(在数组中进行游走不会越界),
        因为有重复数字的出现, 所以这个游走必然是成环的, 环的入口就是重复的元素, 
        即按照寻找链表环入口的思路来做
        **/
    int findDuplicate(vector<int>& nums) {
        if(nums.size() > 1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while(slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while(fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};

//二分思想
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for(auto a : nums) {
                if(a <= mid) {
                    count++;
                }
            }
            if(count <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};

//借助集合
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto a : nums) {
            if(st.count(a) > 0) {
                return a;
            }
            st.insert(a);
        }
        return -1;
    }
};

//排序后判断
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == nums[i+1]) {
                return nums[i];
            }
        }
        return -1;
    }
};
