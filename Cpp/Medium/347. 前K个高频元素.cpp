class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map1;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> res;
        for(auto a : nums) {
            map1[a]++;
        }
        for(auto it : map1) {
            bucket[it.second].push_back(it.first);
        }
        for(int i = nums.size(); i >= 0; i--) {
            for(int j = 0; j < bucket[i].size(); j++) {
                res.push_back(bucket[i][j]);
                if(res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
