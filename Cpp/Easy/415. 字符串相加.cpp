给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。


class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int m = num1.size(),n = num2.size(),i=m-1,j = n-1,carry=0;
        while(i>=0||j>=0){
            int a , b;
            if(i>=0){
                a = num1[i--]-'0';
            }else{
                a = 0;
            }
            if(j>=0){
                b = num2[j--]-'0';
            }else{
                b = 0;
            }
            int sum = a+b+carry;
            res.insert(res.begin(),sum%10+'0');
            carry = sum/10;
        }
        if(carry){
            return "1"+res;
        }else{
            return res;
        }
    }
};
