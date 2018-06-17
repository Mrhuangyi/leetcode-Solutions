给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。

这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。   

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,int> m1;
        unordered_map<string,int> m2;
        istringstream in(str);
        int i = 0;
        for(string word;in>>word;++i){
            if(m1.find(pattern[i])!=m1.end()||m2.find(word)!=m2.end()){
                if(m1[pattern[i]]!=m2[word]){
                    return false;
                }
            }else{
                m1[pattern[i]] = m2[word] = i+1;
            }
        }
        return i==pattern.size();
    }
};
