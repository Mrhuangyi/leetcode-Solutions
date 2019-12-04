/**
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
    
所以返回 [0, 1]
**/
法一：直接双重循环 暴力解，但会超时，O(n^2)
法二：哈希，用一个哈希表，存储每个数的对应下标，复杂度O(n)
    


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++) {
            hashMap[nums[i]] = i;
        } 
        for(int j = 0; j < nums.size(); j++) {
            if(hashMap.find(target-nums[j]) != hashMap.end() && hashMap[target-nums[j]] != j) {
                res.push_back(j);
                res.push_back(hashMap[target-nums[j]]);
                break;
            }
        }
        return res;
    }
};


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
