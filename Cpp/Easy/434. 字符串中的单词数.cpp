统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5

class Solution {
public:
    int countSegments(string s) {
        int res = 0, n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            res++;
            while(i<n&&s[i]!=' '){i++;}
        }
        return res;
    }
};
