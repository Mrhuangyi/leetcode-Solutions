给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。

示例 1:

输入：
nums = [1,3,1]
k = 1
输出：0 
解释：
所有数对如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
提示:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[nums.size() - 1] - nums[0];
        while(low < high) {
            int mid = low + (high - low) / 2;
            int count = 0, left = 0, right = 0;
            while(right < nums.size()) {
                while(nums[right] - nums[left] > mid) {
                    left++;
                }
                count += right - left;
                right++;
            }
            if(count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
