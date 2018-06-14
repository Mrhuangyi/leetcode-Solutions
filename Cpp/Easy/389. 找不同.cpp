给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例:

输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0,sum2 = 0,dif = 0;
        for(int i=0;i<s.size();i++){
            sum1 += s[i];
        }
        for(int i=0;i<t.size();i++){
            sum2 += t[i];
        }
        dif = sum2-sum1;
        return (char)dif;
    }
};
