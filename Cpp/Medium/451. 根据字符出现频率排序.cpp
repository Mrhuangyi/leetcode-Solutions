class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map1;
        for(auto c : s) {
            map1[c]++;
        }
        vector<string> bucket(s.size() + 1);
        for(auto kv : map1) {
            bucket[kv.second].push_back(kv.first);
        }
        string res;
        for(int n = bucket.size() - 1; n >= 0; n--) {
            for(auto c : bucket[n]) {
                res += string(n, c);
            }
        }
        return res;
    }
};
