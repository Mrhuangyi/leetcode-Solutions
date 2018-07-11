实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

C++有直接求下一个排列的库函数，但这题用库函数就没意义了
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};

class Solution {
public:
    void swapWith(int num,vector<int>& nums,int i){
        int min = nums[i];
        int j = i,index = i;
        for(j = i;j<nums.size();j++){
            if( min > nums[j] && nums[j] > nums[num] ){
                index = j;
                min = nums[j];
            }
        }
        swap(nums[index],nums[num]);
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1){
            return ;
        }
        int flag = 0;
        for(int i = nums.size()-1;i > 0;i--){
            if(nums[i] > nums[i-1]){
                swapWith(i-1, nums, i);
                sort(nums.begin()+i,nums.end());
                flag = 1;
                break;
            }
        }
        if( flag == 0 ){
            sort(nums.begin(),nums.end());
        }
    }
};
