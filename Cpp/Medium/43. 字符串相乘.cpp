/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

*/

class Solution {
public:
    const int maxlen = 222;
    string multiply(string num1, string num2) {
        int num[maxlen];
        int len1 = num1.size();
        int len2 = num2.size();
        string res;
        for(int i = 0; i < maxlen; i++) {
            num[i] = 0;
        }
        for(int i = 0; i < len1; i++) {
            for(int j = 0; j < len2; j++) {
                num[i+j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int carry = 0;
        for(int i = len1 + len2 - 2; i >= 0; i--) {
            res.push_back((num[i] + carry) % 10 + '0');
            carry = (num[i] + carry) / 10;
        }
        while(carry > 0) {
            res.push_back(carry % 10 + '0');
            carry = carry / 10;
        }
        for(int i = res.size() - 1; i >= 0; i--) {
            if(res[i] == '0' && i != 0) {
                res.pop_back();
            } else {
                break;
            }
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
