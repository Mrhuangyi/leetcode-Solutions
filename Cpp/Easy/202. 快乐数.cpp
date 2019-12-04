编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例: 

输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

//这题我稍微提一下，一直循环，计算各个数位的平方和能否为1，如果能得到1，那么返回true就完事了
//如果得不到1，你不能一直循环下去，这样会超时，所以考虑开一个集合，存放之前的中间值，每次判断下是不是之前出现过，如果之前出现过，那么直接返回false。
class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        set<int> hashSet;
        while(sum != 1) {
        sum = 0;
        while(n != 0) {
            int x = n % 10;
            n = n / 10;
            sum += x * x;
        }
        n = sum;
        if(hashSet.count(sum) > 0) {
            return false;
        }
        hashSet.insert(sum);
        }
        return sum == 1;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while(1){
            n = numSquareSum(n);
            if(n==1)
                return true;
            if(st.find(n)!=st.end())
                return false;
            st.insert(n);
        }
    }
    int numSquareSum(int n){
        int squareSum = 0;
        while(n){
            squareSum +=(n%10)*(n%10);
            n /=10;
        }
        return squareSum;
    }
};
