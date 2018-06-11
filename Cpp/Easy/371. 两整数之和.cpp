不使用运算符 + 和-，计算两整数a 、b之和。

示例：
若 a = 1 ，b = 2，返回 3。

class Solution {
public:
    int getSum(int a, int b) {
         int sum = 0 ;
        int carry = 0;
        for(int i = 0;i< 32 ;i++){
            int a1 = a & 1;
            int b1 = b & 1;
            int val = 0 ;
            if(a1 == 0 && b1 == 0 && carry == 0){
                val = 0;
                carry = 0;
            }else if(a1 == 1 && b1 == 1 && carry == 1){
                val = 1;
                carry = 1;
            }else if(a1==0 && b1 ==0 || a1 ==0 && carry ==0 || b1 ==0 && carry ==0){
                val = 1;
                carry = 0;
            }else{
                val = 0;
                carry = 1;
            }
            val = val << i;
            sum = sum | val;
            a = a >> 1;
            b = b >> 1;
        }
        return sum;
    }
};
