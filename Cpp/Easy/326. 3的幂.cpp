给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

循环写法：
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        while(n>1){
            if(n%3!=0){
                return false;
            }
            n/=3;
        }
        return true;
    }
};

递归写法：

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        return (n%3==0)&&isPowerOfThree(n/3);
    }
};

可以采用取对数求解，如果一个数是3的幂，那么以3为底取对数结果必然是一个整数。
class Solution {
public:
    bool isPowerOfThree(int n) {
        double result = log10(n)/log10(3);
        return (result==int(result))?true:false;
    }
};
