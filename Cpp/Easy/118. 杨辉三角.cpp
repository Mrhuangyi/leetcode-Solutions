给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

规律：
1. 第k层有k个元素
2. 每层第一个和最后一个为1
3. 对于第k(k>2)层第n(n>1&&n<k)各元素有a[k][n] = a[k-1][n-1]+a[k-1][n]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > vals;
        vals.resize(numRows);
        for(int i=0;i<numRows;i++){
            vals[i].resize(i+1);
            vals[i][0] = 1;
            vals[i][vals[i].size()-1] = 1;
            for(int j=1;j<vals[i].size()-1;j++){
                vals[i][j] = vals[i-1][j-1]+vals[i-1][j];
            }
        }
        return vals;
    }
};
