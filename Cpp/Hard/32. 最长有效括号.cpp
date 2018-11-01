/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
*/
解法一：用栈
LeetCode 20有一题是叫有效的括号，我们的思路是遇到左括号先入栈，遇到右括号，先判断栈是否为空，如果栈为空，直接return false;如果栈不空，则出栈，继续处理后续字符。当处理完所有字符后再判断一次栈是否为空。这道题的思路：
1 用last标记最后一个右括号的位置，开一个栈来跟踪没被匹配的左括号。
2 遍历字符串，当碰到左括号，就将此刻下标压栈，如果碰到右括号，先判断栈是否为空，如果栈是空的，那么将此时的下标i赋给last，如果栈不空，那么出栈，出栈后如果栈是空的，那么取max(maxLen, i - last)，反之，取max(maxLen, i - lefts.top())

时间复杂度O(n)，空间复杂度O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        // 用last标记最后一个“)”的位置
        int maxLen = 0, last = -1;
        //开一个栈用来跟踪没有被匹配的“(”
        stack<int> lefts;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                lefts.push(i);
            } else {
                if(lefts.empty()) {
                    
                    last = i;
                } else {
                    lefts.pop();
                    if(lefts.empty()) {
                        maxLen = max(maxLen, i - last);
                    } else {
                        maxLen = max(maxLen, i - lefts.top());
                    }
                }
            }
        }
        return maxLen;
    }
};

解法二：动态规划

时间复杂度：O(n)，空间复杂度O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> f(s.size(), 0);
        int res = 0;
        for(int i = s.size() - 2; i >= 0; i--) {
            int match = i + f[i + 1] + 1;
            if(s[i] == '(' && match < s.size() && s[match] == ')') {
                f[i] = f[i + 1] + 2;
                if(match + 1 < s.size()) {
                    f[i] += f[match + 1];
                }
            }
            res = max(res, f[i]);
        }
        return res;
    }
};
