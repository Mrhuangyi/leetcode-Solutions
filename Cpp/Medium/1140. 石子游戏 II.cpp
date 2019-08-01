亚历克斯和李继续他们的石子游戏。许多堆石子 排成一行，每堆都有正整数颗石子 piles[i]。游戏以谁手中的石子最多来决出胜负。

亚历克斯和李轮流进行，亚历克斯先开始。最初，M = 1。

在每个玩家的回合中，该玩家可以拿走剩下的 前 X 堆的所有石子，其中 1 <= X <= 2M。然后，令 M = max(M, X)。

游戏一直持续到所有石子都被拿走。

假设亚历克斯和李都发挥出最佳水平，返回亚历克斯可以得到的最大数量的石头。

 

示例：

输入：piles = [2,7,9,4,4]
输出：10
解释：
如果亚历克斯在开始时拿走一堆石子，李拿走两堆，接着亚历克斯也拿走两堆。在这种情况下，亚历克斯可以拿到 2 + 4 + 4 = 10 颗石子。 
如果亚历克斯在开始时拿走两堆石子，那么李就可以拿走剩下全部三堆石子。在这种情况下，亚历克斯可以拿到 2 + 7 = 9 颗石子。
所以我们返回更大的 10。 
 

提示：

1 <= piles.length <= 100
1 <= piles[i] <= 10 ^ 4


class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int len = piles.size();
        vector<vector<int> > dp(len, vector<int>(len, 0));
        vector<int> sum(len, 0);
        sum.back() = piles.back();
        for(int i = len-2; i >= 0; i--) {
            sum[i] = sum[i+1] + piles[i];
        }
        for(int i = len-1; i >= 0; i--) {
            for(int j = 0; j < len; j++) {
                int m = j + 1;
                if(2*m >= len-i) {
                    dp[i][j] = sum[i];
                } else {
                    for(int k = 1; k <= 2*m; k++) {
                        dp[i][j] = max(dp[i][j], sum[i]-dp[i+k][max(k,m)-1]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
