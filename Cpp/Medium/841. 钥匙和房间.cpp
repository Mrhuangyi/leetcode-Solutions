有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。

在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。

最初，除 0 号房间外的其余所有房间都被锁住。

你可以自由地在房间之间来回走动。

如果能进入每个房间返回 true，否则返回 false。

示例 1：

输入: [[1],[2],[3],[]]
输出: true
解释:  
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。
示例 2：

输入：[[1,3],[3,0,1],[2],[0]]
输出：false
解释：我们不能进入 2 号房间。
提示：

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
所有房间中的钥匙数量总计不超过 3000。


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> que; //队列装的是房间号
        int n = rooms.size();
        vector<bool> visit(n,false);
        que.push(0);
        visit[0] = true;
        while (!que.empty())
        {
            int temp = que.front(); //取出当前能到达的房间号
            que.pop();
            for (int i = 0; i < rooms[temp].size();i++) //遍历当前房间里面的能打开房间的钥匙
            {
                int next = rooms[temp][i];
                if (!visit[next]) //还没有被访问
                {
                    visit[next] = true; //不要忘记，标记为已经访问过
                    que.push(next);
                }
            }
        }

        for (int i = 0; i < n;i++)
        {
            if (visit[i]==false)
            {
                return false;
            }
        }
        return true;
    }
};
