根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        int n = T.size();
        vector<int> res(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && T[i] >= T[s.top()]) {
                s.pop();
            }
            if(s.empty()) {
                res[i] = 0;
            } else {
                res[i] = s.top() - i;
            }
            s.push(i);
        }
        return res;
    }
};
