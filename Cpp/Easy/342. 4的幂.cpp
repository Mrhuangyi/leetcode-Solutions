给定一个整数 (32位有符整数型)，请写出一个函数来检验它是否是4的幂。

示例:
当 num = 16 时 ，返回 true 。 当 num = 5时，返回 false。

问题进阶：你能不使用循环/递归来解决这个问题吗？

循环写法：
class Solution {
public:
    bool isPowerOfFour(int num) {
         if(num<=0){
            return false;
        }
        while(num>1){
            if(num%4!=0){
                return false;
            }
            num/=4;
        }
        return true;
    }
};

递归写法：
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0){
            return false;
        }
        if(num==1){
            return true;
        }
        return (num%4==0)&&isPowerOfFour(num/4);
    }
};

对数写法：
class Solution {
public:
    bool isPowerOfFour(int num) {
       double result = log10(num)/log10(4);
        return (result==int(result))?true:false;
    }
};
