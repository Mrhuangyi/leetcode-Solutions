class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        vector<int> s(n+1);
        for(int i = 1; i <= n; i++) {
            s[i] = s[i-1] + data[i-1];
        }
        int m = s[n];
        int res = n;
        for(int i = m; i <= n; i++) {
            res = min(res, m - (s[i] - s[i-m]));
        }
        return res;
    }
};
