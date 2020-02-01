给你一个 m * n 的整数矩阵 mat ，请你将同一条对角线上的元素（从左上到右下）按升序排序后，返回排好序的矩阵。

 

示例 1：



输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-the-matrix-diagonally
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int row = mat.size(), col = mat[0].size();
        if(row == 1) {
         return mat;   
        }
        vector<vector<int> > res(row, vector<int>(col));
        int iStart = 0;  
        int jStart = col - 1;
        while (iStart < row) {  
            vector<int> temp;
            for (int i = iStart, j = jStart; i < row && j < col; i++, j++) {  
                  temp.push_back(mat[i][j]);
                res[i][j] = mat[i][j];
            }
            sort(temp.begin(), temp.end());
            int t = 0;
            for (int i = iStart, j = jStart; i <= row - 1 && j <= col - 1; i++, j++) {  
                  res[i][j] = temp[t];
                t++;
            }
            if (jStart > 0) {  
                jStart--;  
            } else {  
                iStart++;  
            }
        }  
        return res;
    }  
};
