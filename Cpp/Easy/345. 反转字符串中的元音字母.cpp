编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1：
给定 s = "hello", 返回 "holle".

示例 2：
给定 s = "leetcode", 返回 "leotcede".

注意:
元音字母不包括 "y".

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> pos(s.size());
        set<char> vowel;
        int cnt = 0;
        vowel.insert('a');
        vowel.insert('e');
        vowel.insert('i');
        vowel.insert('o');
        vowel.insert('u');
        vowel.insert('A');
        vowel.insert('E');
        vowel.insert('I');
        vowel.insert('O');
        vowel.insert('U');
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(vowel.count(s[i])){
                pos[cnt] = i;
                cnt++;
            }
            ans += s[i];
        }
        
        for(int i=0;i<cnt;i++){
            ans[pos[i]] = s[pos[cnt-i-1]];
        }
        return  ans;
    }
};
