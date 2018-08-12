给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            ++left;
            --right;
        }
        return true;
    }
    bool isPalindrome(string& s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
