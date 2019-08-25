class Solution {
private:
    int const static maxv = 5001;
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        int num = 0;
        queue<int> q;
        int inD[maxv];
        vector<int> edge[maxv];
        memset(inD, 0, sizeof(inD));
        for(int i = 0; i < relations.size(); i++) {
            inD[relations[i][1]]++;
            edge[relations[i][0]].push_back(relations[i][1]);
        }
        int b[maxv];
        int res = 0;
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= N; i++) {
            if(inD[i] == 0) {
                q.push(i);
                b[i] = 1;
                res = 1;
                num++;
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = 0; i < edge[u].size(); i++) {
                int v = edge[u][i];
                inD[v]--;
                if(inD[v] == 0) {
                    q.push(v);
                    b[v] = b[u] + 1;
                    res = b[u] + 1;
                    num++;
                }
            }
        }
        if(num == N) {
            return res;
        } else {
            return -1;
        }
    }
};
