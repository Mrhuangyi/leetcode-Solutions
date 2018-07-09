给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

class Solution {
public:
    int longestPalindrome(string s) {
        int a[256] = {0};
        for(int i=0;i<s.size();i++){
            a[s[i]]++;
        }
        int sum = 0;
        bool flag = false;
        for(int i=0;i<256;i++){
            if(a[i]==s.size()){
                return a[i];
            }
            if(a[i]>=2&&a[i]%2==0){
                sum+=a[i];
            }else if(a[i]>2&&a[i]%2!=0){
                sum+=(a[i]-1);
                flag = true;
            }else if(a[i]==1){
                flag = true;
            }
        }
        if(flag){
            return sum+1;
        }else{
            return sum;
        }
    }
};
