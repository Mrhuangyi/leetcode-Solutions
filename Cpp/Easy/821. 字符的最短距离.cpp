给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。

示例 1:

输入: S = "loveleetcode", C = 'e'
输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
说明:

字符串 S 的长度范围为 [1, 10000]。
C 是一个单字符，且保证是字符串 S 里的字符。
S 和 C 中的所有字母均为小写字母。

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> ans(n, n);
        for(int i = 0; i < n; i++) {
            if(S[i] == C) {
                ans[i] = 0;
            }
        }
        for(int i = 1; i < n; i++) {
            ans[i] = min(ans[i], ans[i - 1] + 1);
        }
        for(int i = n - 2; i >= 0; i--) {
            ans[i] = min(ans[i], ans[i + 1] + 1);
        }
        return ans;
    }
};
