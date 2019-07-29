统计所有小于非负数整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

正解：埃士筛法

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n,true);
        for(int i=2;i*i<n;i++){
            if(isPrime[i]){
                for(int j=i*i;j<n;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                cnt++;
            }
        }
        return cnt;
    }
  
};

暴力解法：
超时：
class Solution {
public:
    static bool isPrime(int n) {
        if(n < 2) {
            return false;
        }
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) 
                return false;
        }
        return true;
    }
    
    int countPrimes(int n) {
        int res = 0;
        while(n) {
            n--;
            if(isPrime(n)) {
                res++;
            }
           
        }
        return res;
    }
};
