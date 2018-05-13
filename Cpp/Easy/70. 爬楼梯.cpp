假设你正在爬楼梯。需要 n 步你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 步 + 1 步
2.  2 步
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 步 + 1 步 + 1 步
2.  1 步 + 2 步
3.  2 步 + 1 步

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) 
            return n;
        int* step = new int[n];
        step[0] = 1;
        step[1] = 2;
        for(int i=2;i<n;i++){
            step[i] = step[i-1]+step[i-2];
        }
        return step[n-1];
    }
};
