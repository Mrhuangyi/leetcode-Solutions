/*
编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1,1);
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        for(int i = 1; i < n; i++) {
            int m2 = res[index2] * 2;
            int m3 = res[index3] * 3;
            int m5 = res[index5] * 5;
            int cur = min(m2, min(m3, m5));
            if(cur == m2) {
                index2++;
            }
            if(cur == m3) {
                index3++;
            }
            if(cur == m5) {
                index5++;
            }
            res.push_back(cur);
        }
        return res.back();
    }
};
