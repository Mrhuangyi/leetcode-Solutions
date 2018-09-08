假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例 2：

输入: [2,2,2,0,1]
输出: 0

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) {
            return 0;
        } else if(size == 1) {
            return nums[0];
        } else if(size == 2) {
            return min(nums[0], nums[1]);
        }
        int left = 0;
        int right = size - 1;
        while(left < right - 1) {
            if(nums[left] < nums[right]) {
                return nums[left];
            }
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[left]) {
                left = mid;
            } else if(nums[mid] < nums[left]) {
                right = mid;
            } else {
                left++;
            }
        }
        return min(nums[left], nums[right]);
    }
};
