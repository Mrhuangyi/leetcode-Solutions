给定一个非负整数 num。 对于范围 0 ≤ i ≤ num 中的每个数字 i ，计算其二进制数中的1的数目并将它们作为数组返回。

示例：
比如给定 num = 5 ，应该返回 [0,1,1,2,1,2].

进阶：

给出时间复杂度为O(n * sizeof(integer)) 的解答非常容易。 但是你可以在线性时间O(n)内用一次遍历做到吗？
要求算法的空间复杂度为O(n)。
你能进一步完善解法吗？ 在c ++或任何其他语言中不使用任何内置函数（如c++里的 __builtin_popcount）来执行此操作


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0;i<=num;i++){
                int x = count(i);
                res.push_back(x);
        }
        return res;
    }
    int count(int n){
        int cnt = 0;
        while( n ){
            if( n%2 == 1 ){
                cnt++;
            }
            n /= 2;
        }
        return cnt;
    }
};
