给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]


class Solution {
public:
    vector<vector<string> > res;
    vector<string> temp;
    
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void backtrack(string s, int a, int b) {
        if(a > b) {
            res.push_back(temp);
            return;
        }
        for(int i = 1; i <= b - a + 1; i++) {
            if(isPalindrome(s.substr(a, i))) {
                temp.push_back(s.substr(a, i));
                backtrack(s, a + i, b);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s, 0, s.size() - 1);
        return res;
    }
};
