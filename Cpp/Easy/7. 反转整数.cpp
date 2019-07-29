/*
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

1. 考虑负数的情况
2. 考虑溢出，包括正溢出和负溢出，即如果是正数，则大于2147483647溢出；如果是负数，则小于-2147483648溢出
*/


class Solution {
public:
    int reverse(int x) {
        long long temp = x;
        bool sign;
        if(x < 0) {
            sign = false;
            temp = -temp;
        } else {
            sign = true;
        }
        long long newNum = 0;
        while(temp != 0) {
            int t = temp % 10;
            newNum += t;
            temp = temp / 10;
            if(temp == 0) {
                break;
            }
            newNum = newNum * 10;
        }
        if(newNum > 2147483647 || (!sign && newNum > 2147483648)){
            return 0;
        }
        if(sign) {
            return newNum;
        } else {
            return -newNum;
        }
    }
};
