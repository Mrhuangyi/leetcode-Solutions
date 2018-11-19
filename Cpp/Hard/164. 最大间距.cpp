/*
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1:

输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
示例 2:

输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
说明:

你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int res = 0;
        if(nums.size() < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};

int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int maxVal = *max_element(nums.begin(), nums.end());

    int exp = 1;                                 // 1, 10, 100, 1000 ...
    int radix = 10;                              // base 10 system

    vector<int> aux(nums.size());

    /* LSD Radix Sort */
    while (maxVal / exp > 0) {                   // Go through all digits from LSD to MSD
        vector<int> count(radix, 0);

        for (int i = 0; i < nums.size(); i++)    // Counting sort
            count[(nums[i] / exp) % 10]++;

        for (int i = 1; i < count.size(); i++)   // you could also use partial_sum()
            count[i] += count[i - 1];

        for (int i = nums.size() - 1; i >= 0; i--)
            aux[--count[(nums[i] / exp) % 10]] = nums[i];

        for (int i = 0; i < nums.size(); i++)
            nums[i] = aux[i];

        exp *= 10;
    }

    int maxGap = 0;

    for (int i = 0; i < nums.size() - 1; i++)
        maxGap = max(nums[i + 1] - nums[i], maxGap);

    return maxGap;
}
