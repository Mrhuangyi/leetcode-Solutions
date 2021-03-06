给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？

解法：滚动数组

我们知道，帕斯卡三角的计算公式是这样的，A[k][n]	=	A[k-1][n-1] +	A[k-1][n]。
假设现在数组存放的第3层的数据，[1,	3,	3,	1]，如果我们需要计算第4层的数据， 如果我们从前往后计算，譬如A[4][2]=	A[3][1]	+	A[3][2]，也就是4，但是因为只有一 个数组，所以需要将4这个值覆盖到2这个位置，那么我们计算A[4][3]的时候就会出 现问题了，因为这时候A[3][2]不是3，而是4了。
为了解决这个问题，我们只能从后往前计算，仍然是上面那个例子，我们实现计算 A[4][3]	=	A[3][2]	+	A[3][3]，也就是6，我们将6直接覆盖到3这个位置，但不会影响 我们计算A[4][2]，因为A[4][2]	=	A[3][1]	+	A[3][2]，已经不会涉及到3这个位置了。

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> array;
        for(int i=0;i<=rowIndex;i++){
          for (int j = i - 1; j > 0; j--){ 
              array[j] = array[j - 1] + array[j];
          }
            array.push_back(1);

        }
        return array;
    }
};
