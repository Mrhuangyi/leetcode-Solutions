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
