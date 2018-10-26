/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, "", res);
        return res;
    }
    void generate(int left, int right, string s, vector<string>& res) {
        if(left == 0) {
            while(right--) {
                s += ")";
            }
            res.push_back(s);
        } else if(right > left) {
            generate(left - 1, right, s + "(", res);
            generate(left, right - 1, s + ")", res);
        } else {
            generate(left - 1, right, s + "(", res);
        }
    }
};
