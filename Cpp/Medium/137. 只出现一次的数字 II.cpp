给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99
解法一：
创建一个长度为sizeof(int)的数组count[sizeof(int)]，用count[i]来表示在i位出现的1的次数，如果count[i]是3的倍数，跳过，否则，取出该位。
时间复杂度O(n),空间复杂度O(1)


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int w = sizeof(int) * 8;
        int count[w];
        fill_n(&count[0], w, 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < w; j++) {
                count[j] += (nums[i] >> j) & 1;
                count[j] %= 3;
            }
        }
        int res = 0;
        for(int i = 0; i < w; i++) {
            res += count[i] << i;
        }
        return res;
    }
};


解法二：
用二进制模拟三进制运算。
用one记录到当前处理的元素为止，二进制1出现“1次”（mod 3 之后的 1）的有哪些二进制位；用two记录到当前计算的变量为止，二进制1出现“2次”（mod 3 之后的 2）的有哪些二进制位。当one和two中的某一位同时为1时表示该二进制位上1出现了3次，此时需要清零。


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one  = 0, two = 0, three = 0;
        for(auto i : nums) {
            two |= (one & i);
            one ^= i;
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        return one;
    }
};


参考：https://soulmachine.gitbooks.io/algorithm-essentials/java/bitwise-operations/single-number-ii.html
