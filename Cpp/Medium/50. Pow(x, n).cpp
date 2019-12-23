/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/


//快速幂解法
class Solution {
public:
    double myPow(double x, int n) {
        long long b = abs((long long)n);
        double pow = 1.0;
        double temp = x;         // base的（2的整数幂）次幂
        if (n == 0) {
            return 1;
        }
        while (b) {
            if (b & 1) {        // 逐位检查
                pow *= temp;
            }      
            temp *= temp;            // temp翻倍
            b >>= 1;    // 检查下一位
        }
        if (n < 0) {
            pow = 1 / pow;
        }
        return pow;
    }
};


class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i = n; i != 0; i /= 2) {
            if(i % 2 != 0) {
                res *= x;
            }
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};
