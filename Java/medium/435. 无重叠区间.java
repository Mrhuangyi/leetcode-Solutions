class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals == null || intervals.length <= 1) {
            return 0;
        }
        Arrays.sort(intervals, (o1, o2) -> {
            if(o1[0] != o2[0]) {
                return o1[0] - o2[0];
            }
            return o1[1] - o2[1];
        });
        int cnt = 0;
        int pre = 0;
        for(int i = 1; i < intervals.length; i++) {
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
}
