给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。

示例:

输入:
[[0,0],[1,0],[2,0]]

输出:
2

解释:
两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int len = points.size();
        int res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                int x = points[i].first - points[j].first;
                int y = points[i].second - points[j].second;
                m[x * x + y * y]++;
            }
        unordered_map<int, int> :: iterator it;
        for(it = m.begin(); it != m.end(); it++) {
            int temp = it->second;
            res += temp * (temp - 1);
        }
            m.clear();
        }
        return res;
    }
};
