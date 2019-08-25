//并查集可以通过查询两个结点所在集合的根结点是否相同来判断他们是否在同一个集合
//而只要把测试边的两个端点所在集合合并，就能达到将边加入最小生成树的效果
class UnionSet{
public:
    vector<int> father;
    UnionSet(int n) {
        father.resize(n+1);
        for(int i = 1; i <= n; i++) {
            father[i] = i;
        }
    }
    
    int find(int x) {
        while(father[x] != x) {
            x = father[x];
        }
        return x;
    }
    
    void insert(int x, int y) {
        father[find(x)] = y;
    }
    
    // int count() {
    //     int cnt = 0;
    //     for(int i = 1; i <= father.size(); i++) {
    //         if(father[i] == i) {
    //             cnt++;
    //         }
    //     }
    //     return cnt;
    // }
};
class Solution {
public:
    //const static int maxv = 10002;
    static bool cmp(vector<int>& e1, vector<int>& e2) {
        return e1[2] < e2[2];
    }
    int minimumCost(int N, vector<vector<int>>& conections) {
        UnionSet un = UnionSet(N);
        //对所有边按边权从小到大排序
        sort(conections.begin(), conections.end(), cmp);
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < conections.size(); i++) {
        //按边权从小到大测试所有边，如果当前测试边所连接的两个顶点不在同一个连通块中，则把这条测试边加入到当前最小生成树中；否则，将边舍弃
            if(un.find(conections[i][0]) != un.find(conections[i][1])) {
                un.insert(conections[i][0], conections[i][1]);
                cnt++;
                sum += conections[i][2];
            }
        }
        //直到最小生成树中的边数等于总顶点数减1或是测试完所有边时结束
        if(cnt == N - 1) {
            return sum;
        } else {
            return -1;
        }
    }
};
