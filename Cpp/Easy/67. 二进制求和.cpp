给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size(), len2 = b.size();
        if(len1 == 0) {
            return b;
        }
        if(len2 == 0) {
            return a;
        }
        string res;
        int i = len1 - 1;
        int j = len2 - 1;
        int carry = 0;
        while(i >= 0 || j >= 0) {
            if(i >= 0) {
                carry += a[i--] - '0';
            }
            if(j >= 0) {
                carry += b[j--] - '0';
            }
            res += to_string(carry % 2);
            carry >>= 1;
        }
        reverse(res.begin(), res.end());
        return carry > 0 ? '1' + res : res;
    }
};
    
    
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        if(len1==0){
            return b;
        }
        if(len2==0){
            return a;
        }
        string ret;
        int carry = 0;
        int index1 = len1-1;
        int index2 = len2-1;
        while(index1>=0&&index2>=0){
            int num = (a[index1]-'0')+(b[index2]-'0')+carry;
            carry = num/2;
            num = num%2;
            index1--;
            index2--;
            ret.insert(ret.begin(),num+'0');
        }
        if(index1<0&&index2<0){
            if(carry==1){
                ret.insert(ret.begin(),carry+'0');
                return ret;
            }
        }
        while(index1>=0){
            int num = (a[index1]-'0')+carry;
            carry = num/2;
            num = num%2;
            index1--;
            ret.insert(ret.begin(),num+'0');
        }
        while(index2>=0){
            int num = (b[index2]-'0')+carry;
            carry = num/2;
            num = num%2;
            index2--;
            ret.insert(ret.begin(),num+'0');
        }
        if(carry==1){
            ret.insert(ret.begin(),carry+'0');
           
        }
         return ret;
    }
};
