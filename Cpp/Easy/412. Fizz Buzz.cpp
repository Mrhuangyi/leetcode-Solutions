写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        while(n!=0){
            if(n%5==0&&n%3==0){
                res.push_back("FizzBuzz");
            }else if(n%5==0&&n%3!=0){
                res.push_back("Buzz");
            }else if(n%5!=0&&n%3==0){
                res.push_back("Fizz");
            }else{
                string s = to_string(n);
                res.push_back(s);
            }
            n--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
