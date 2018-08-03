你需要找到由两个 n 位数的乘积组成的最大回文数。

由于结果会很大，你只需返回最大回文数 mod 1337得到的结果。

示例:

输入: 2

输出: 987

解释: 99 x 91 = 9009, 9009 % 1337 = 987

说明:

n 的取值范围为 [1,8]。

class Solution {
public:
    int largestPalindrome(int n) {
        int upper = pow(10, n) - 1, lower = upper / 10;
        for(int i = upper; i > lower; i--) {
            string t = to_string(i);
            long p = stol(t + string(t.rbegin(), t.rend()));
            for(long j = upper; j * j > p; j--) {
                if(p % j == 0) {
                    return p % 1337;
                }
            }
        }
        return 9;
    }
};
