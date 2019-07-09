给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 

提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res(A.size());
        int left = 0;
        int right = A.size() - 1;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] % 2 == 0) {
                res[left++] = A[i];
            } else {
                res[right--] = A[i];
            }
        }
        return res;
    }
};

