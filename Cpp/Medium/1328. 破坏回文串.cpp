给你一个回文字符串 palindrome ，请你将其中 一个 字符用任意小写英文字母替换，使得结果字符串的字典序最小，且 不是 回文串。

请你返回结果字符串。如果无法做到，则返回一个空串。

 

示例 1：

输入：palindrome = "abccba"
输出："aaccba"
示例 2：

输入：palindrome = "a"
输出：""
 

提示：

1 <= palindrome.length <= 1000
palindrome 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/break-a-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    string breakPalindrome(string palindrome) {
        string res;
        if(palindrome.size() == 1) {
            return res;
        }
        char temp;
        for(int i = 0; i < palindrome.size(); i++) {
            if(palindrome[i] != 'a') {
                temp = palindrome[i];
                palindrome[i] = 'a';
            } else {
                continue;
            }
            if(!isPalindrome(palindrome)) {
                return palindrome;
            } else {
                palindrome[i] = temp;
            }
        }
        for(int i = palindrome.size()-1; i >= 0; i--) {
            if(palindrome[i] != 'b') {
                temp = palindrome[i];
                palindrome[i] = 'b';
            } else {
                continue;
            }
            if(!isPalindrome(palindrome)) {
                return palindrome;
            } else {
                palindrome[i] = temp;
            }
        }
        return res;
    }
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            while(i<j && !isdigit(s[i]) && !isalpha(s[i]))i++;
            while(i<j && !isdigit(s[j]) && !isalpha(s[j]))j--;
            if(i<j && tolower(s[i])!=tolower(s[j]))
                return false;
            i++;j--;
        }
        return true;
    }
};
