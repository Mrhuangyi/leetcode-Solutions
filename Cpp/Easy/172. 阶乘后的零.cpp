给定一个整数 n，返回 n! 结果尾数中零的数量。

示例 1:

输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
示例 2:

输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
说明: 你算法的时间复杂度应为 O(log n) 。

尾随零通常由素数因子2和5产生。如果我们可以计数5s和2s的数量，我们的任务就完成了
Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
class Solution {
public:
    int trailingZeroes(int n) {
         int count = 0;
 
    while(n=n/5) count+=n;
 
    return count;
    }
};
