给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:

输入: "abab"

输出: True

解释: 可由子字符串 "ab" 重复两次构成。
示例 2:

输入: "aba"

输出: False
示例 3:

输入: "abcabcabcabc"

输出: True

解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=n/2;i>0;i--){
            string s2 = "";
            if(n%i==0){
                int c = n/i;
                 for(int j=0;j<c;j++){
                s2 += s.substr(0,i);
            }
            } 
            if(s==s2){
                return true;
            }
        }
        return false;
    }
};
