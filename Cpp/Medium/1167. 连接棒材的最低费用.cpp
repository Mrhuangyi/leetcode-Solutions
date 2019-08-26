为了装修新房，你需要加工一些长度为正整数的棒材 sticks。

如果要将长度分别为 X 和 Y 的两根棒材连接在一起，你需要支付 X + Y 的费用。 由于施工需要，你必须将所有棒材连接成一根。

返回你把所有棒材 sticks 连成一根所需要的最低费用。注意你可以任意选择棒材连接的顺序。

 

示例 1：

输入：sticks = [2,4,3]
输出：14
解释：先将 2 和 3 连接成 5，花费 5；再将 5 和 4 连接成 9；总花费为 14。
示例 2：

输入：sticks = [1,8,3,5]
输出：30
 

提示：

1 <= sticks.length <= 10^4
1 <= sticks[i] <= 10^4



class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> Q;
    int connectSticks(vector<int>& sticks) {
        long long res = 0;
        for(int i = 0; i < sticks.size(); i++) {
            Q.push(sticks[i]);
        }
        while(Q.size()>1){
				int a, b;
				a = Q.top();
				Q.pop();
				b = Q.top();
				Q.pop();
				res += (a + b);
				Q.push(a + b);
		}

        return res;
    }
};
