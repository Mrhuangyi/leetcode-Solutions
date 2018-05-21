实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

一道字符串匹配的问题：
方法一：暴力解法，时间复杂度O(m*n)

方法二：KMP算法

方法三：Boyer-Mooer算法

方法四：Rabin-Karp算法

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j, lenh = haystack.length(), lenn = needle.length();
        if (lenn == 0)  return 0;
        for (i = 0; i <= lenh - lenn; i++) {
            for (j = 0; j < lenn; j++) 
                if (haystack[i + j] !=  needle[j]) break;
            // 匹配成功
            if (j == lenn)  return i;
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> KMPpreprocessing(string s) {
        int n = s.size();
        vector<int> match(n,-1);
        int j = -1;
        for(int i=1; i<n; i++) {
            while(j>=0 && s[i]!=s[j+1]) j = match[j];
            if(s[i]==s[j+1]) j++;
            match[i] = j;
        }
        return match;
    }
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        int m = haystack.size(), n = needle.size();
        vector<int> match = KMPpreprocessing(needle);
        int j = -1;
        for(int i=0; i<m; i++) {
            while(j>=0 && haystack[i]!=needle[j+1]) j = match[j];
            if(haystack[i]==needle[j+1]) j++;
            if(j==n-1) return (i-n+1);
        }
        return -1;
    }
};
