给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

 

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

解释:

 

说明:

给定矩阵中的元素总数不会超过 100000 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diagonal-traverse
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) {
            return res;
        }
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = 0;
        res.resize(row * col);
        for(int i = 0; i < row * col; i++) {
            res[i] = matrix[r][c];
            if((r + c) % 2 == 0) {
                if(c == col - 1) {
                    r++;
                } else if(r == 0) {
                    c++;
                } else {
                    r--;
                    c++;
                }
            } else {
                if(r == row - 1) {
                    c++;
                } else if(c == 0) {
                    r++;
                } else {
                    r++;
                    c--;
                }
            }
        }
        return res;
    }
};
