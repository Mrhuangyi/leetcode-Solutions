class Solution {
    static bool cmp(const vector<int> a, const vector<int> b) {
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int pre = 0;
        int cnt = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[pre][1] > intervals[i][0]) {
                cnt++;
                if(intervals[pre][1] > intervals[i][1]) {
                    pre = i;
                }
            } else {
                pre = i;
            }
        }
        return cnt;
    }
};
