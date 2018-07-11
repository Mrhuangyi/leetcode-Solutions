给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return res;
    }
};

class Solution {
public:
    void dfs(int cur,vector<int>& nums,vector<vector<int>>& ans){
        if( cur == nums.size() - 1 ){
            ans.push_back(nums);
            return ;
        }
        for(int i = cur; i < nums.size(); i++){
            swap( nums[cur], nums[i] );
            dfs( cur + 1,nums, ans );
            swap( nums[cur], nums[i] );
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs( 0, nums, res );
        return res;
    }
};
