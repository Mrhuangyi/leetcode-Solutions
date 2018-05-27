给定一个整数，写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
示例 2:

输入: 16
输出: true
示例 3:

输入: 218
输出: false

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        bool hasOne = false;
        while(n>0){
            if(n&1){
                if(hasOne){
                    return false;
                }else{
                    hasOne = true;
                }
            }
            n>>=1;
        }
        return hasOne;
    }
};
