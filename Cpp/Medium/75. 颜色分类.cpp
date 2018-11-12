/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？
*/

法一，计数排序。

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int k = 0;
        for(int p = 0; p < n; p++) {
            if(nums[p] == 0) {
                i++;
            } else if(nums[p] == 1) {
                j++;
            } else {
                k++;
            }
        }
        for(int p = 0; p < n; p++) {
            if(p < i) {
                nums[p] = 0;
            } else if(p >= i && p < i + j) {
                nums[p] = 1;
            } else {
                nums[p] = 2;
            }
        }
    }
};

法二：双指针

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while(middle <= right) {
            if(nums[middle] == 0) {
                swap(nums[left],nums[middle]);
                left++;
                middle++;
            } else if(nums[middle] == 1) {
                middle++;
            } else {
                swap(nums[middle], nums[right]);
                right--;
            }
        }
    }
};
