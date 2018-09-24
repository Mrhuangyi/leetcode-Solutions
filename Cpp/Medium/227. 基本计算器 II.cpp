实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:

输入: "3+2*2"
输出: 7
示例 2:

输入: " 3/2 "
输出: 1
示例 3:

输入: " 3+5 / 2 "
输出: 5
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

class Solution {
public:
    int calculate(string s) {
        int result = 0, inter_res = 0, num = 0;
        char op = '+';
        char ch;
        for(int pos = s.find_first_not_of(' '); pos < s.size(); pos = s.find_first_not_of(' ', pos)) {
            ch = s[pos];
            if(ch >= '0' && ch <= '9') {
                int num = ch - '0';
                while(++pos < s.size() && s[pos] >= '0' && s[pos] <= '9') 
                    num = num * 10 + s[pos] - '0';
                switch(op) {
                    case '+':
                        inter_res += num;
                        break;
                    case '-':
                        inter_res -= num;
                        break;
                    case '*':
                        inter_res *= num;
                        break;
                    case '/':
                        inter_res /= num;
                        break;
                }
            } else {
                if(ch == '+' || ch == '-') {
                    result += inter_res;
                    inter_res = 0;
                }
                op = s[pos++];
            }
        }
        return result + inter_res;
    }
};
