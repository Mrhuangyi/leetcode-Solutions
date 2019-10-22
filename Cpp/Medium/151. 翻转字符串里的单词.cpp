/*
给定一个字符串，逐个翻转字符串中的每个单词。

示例:  

输入: "the sky is blue",
输出: "blue is sky the".
说明:

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。
*/


class Solution {
public:
    string reverseWords(string s) {
        string res,temp;
        reverse(s.begin(), s.end());
        int len = s.size();
        int j = 0;
        while(j < len) {
            while(s[j] == ' ') {
                j++;
                
            }
             
            while(s[len-1] == ' ') {
                len--;
            }
            if(s[j] != ' ' && s[len-1] != ' ') {
                break;
            }
        }
        for(int i = j; i < len; i++) {
            while(s[i] != ' ' && i < len) {
                temp += s[i];
                i++;
            }
            if(s[i] == ' ' && i != len) {
                reverse(temp.begin(), temp.end());
                res += temp;
                res += " ";
                temp = "";
                while(s[i+1] == ' ') {
                    i++;
                }
            }
        }
        reverse(temp.begin(), temp.end());
        res += temp;
        return res;
    }
};


class Solution {
public:
    void reverseWords(string &s) {
        string res = "";
        int i = s.length() - 1;
        while(i >= 0) {
            while(i >= 0 && s[i] == ' ') {
                i--;
            }
            if(i < 0) {
                break;
            }
            if(res.length() != 0) {
                res.push_back(' ');
            }
            string temp = "";
            while(i >= 0 && s[i] != ' ') {
                temp = s[i] + temp;
                i--;
            }
            res.append(temp);
        }
        s = res;
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        //string res = "";
        int n = s.size();
        int i = 0, j = 0, start = 0;
        while(i < n) {
            while(i < n && s[i] == ' ') {
                i++;
            }
            if(i < n && j > 0) {
                s[j++] = ' ';
            }
            start = j;
            while(i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
            reverse(s.begin() + start, s.begin() + j);
        }
        s.resize(j);
        reverse(s.begin(), s.end());
        
    }
};

//C language
void reverse(char *start,char *end)
{
    while(end > start)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++,end--;
    }
}

void trim(char *S)
{
    int count = 0;
    int N = strlen(S);
    int flag = 1;
    for(int i=0;i<N;i++)
    {
        if(S[i] != ' ')
        {
            S[count++] = S[i];
            flag = 0;
        }
        else
        {
            if(!flag)
            {
                S[count++] = S[i];
                flag = 1;
            }
        }
    }
    if(count >= 1 && S[count-1] == ' ')
        S[count-1] = '\0';
    else
        S[count] = '\0';
}

void reverseWords(char *S)
{
    trim(S);
    char *temp = S,*prev = S;
    while(*temp)
    {
        temp++;
        if(*temp == ' ')
        {
            reverse(prev,temp-1);
            prev = temp+1;
        }
        else if(*temp == '\0')
        {
            reverse(prev,temp-1);
        }
    }
    reverse(S,temp-1);
}
