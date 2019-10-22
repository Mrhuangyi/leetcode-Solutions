给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。


class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        int index = 0;  
    for (int i = 0; i <= s.length(); ++i) {
      if (i == s.length() || s[i] == ' ') {
        reverse(s.begin() + index, s.begin() + i);
        index = i + 1;
      }
    }
    return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++) {
            string temp = "";
            while(s[i] != ' ' && s[i] != '\0') {
                temp += s[i];
                i++;
            }
            end = i - 1;
            reverse(temp.begin(), temp.end());
            start = i + 1;
            res += temp;
            if(i != s.size()) {
                res += " ";
            }
        }
        return res;
    }
};
