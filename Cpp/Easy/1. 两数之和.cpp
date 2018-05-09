法一：直接双重循环 暴力解，但会超时，O(n^2)
法二：哈希，用一个哈希表，存储每个数的对应下标，复杂度O(n)
    
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
           const int gap = target-nums[i];
            if(m.find(gap)!=m.end()&&m[gap]>i){
                result.push_back(i);
                result.push_back(m[gap]);
                break;
            }
        }
        return result;
    }
};
