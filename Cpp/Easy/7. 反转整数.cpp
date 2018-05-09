1. 考虑负数的情况
2. 考虑溢出，包括正溢出和负溢出，即如果是正数，则大于2147483647溢出；如果是负数，则小于-2147483648溢出
class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        long long t = x;
        if(t<0){
            t=-t;
        }
        for(;t;t/=10){
            r=r*10+t%10;
        }
        bool sign;
        if(x>0){
            sign = false;
        }
        else{
            sign =true;
        }
        if(r>2147483647||(sign&&r>2147483648)){
            return 0;
        }else{
            if(sign){
                return -r;
            }else{
                return r;
            }
        }
    }
};
