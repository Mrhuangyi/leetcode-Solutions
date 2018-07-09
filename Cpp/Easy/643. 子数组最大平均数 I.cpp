给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

示例 1:

输入: [1,12,-5,-6,50,3], k = 4
输出: 12.75
解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 

注意:

1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        double max = -10001,sum = 0;
        int j = 0;
        if(nums.size()==1){
            return double(nums[0]);
        }
            while(k+j<=nums.size()){
                sum = 0;
        for(int i=j;i<k+j;i++){
            sum += nums[i];
        }
        avg = sum/k;
        if(avg>max){
            max = avg;
        }
        j++;
            }
        return max;
    }
};
