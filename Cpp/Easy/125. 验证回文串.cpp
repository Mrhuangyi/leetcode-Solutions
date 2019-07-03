给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false


class Solution {
public:
    bool isPalindrome(string s) {
       if(s.size()==0){
           return true;
       }
        string res = "";
        for(int i=0;i<s.size();i++){
            if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                res+=s[i];
            }
        }
        transform(res.begin(),res.end(),res.begin(),::tolower);
        int i=0,j=res.size()-1;
        while(i<j){
            if(res[i]!=res[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


class Solution {
public:
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
