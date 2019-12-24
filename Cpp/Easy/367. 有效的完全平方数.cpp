给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

注意：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入： 16

输出： True
 

示例 2：

输入： 14

输出： False

法一：二分

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 0,right = num;
        while(left<=right){
            long long mid = left+(right-left)/2,t=mid*mid;
            if(t==num){
                return true;
            }else if(t<num){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2) {
            return true;
        }
        int left = 1, right = num;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(mid * mid == num) {
                return true;
            } else if(mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return false;
    }
};

法二：
任意完全平方数都可以表示成连续的奇数和

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while(num>0){
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
