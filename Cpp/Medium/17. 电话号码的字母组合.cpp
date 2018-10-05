/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> dic;
        string temp;
        if(digits == "") {
            return res;
        }
        dic.push_back(" ");
        dic.push_back(" ");
        dic.push_back("abc");
        dic.push_back("def");
        dic.push_back("ghi");
        dic.push_back("jkl");
        dic.push_back("mno");
        dic.push_back("pqrs");
        dic.push_back("tuv");
        dic.push_back("wxyz");
        combinations(res, temp, digits, dic, 0);
        return res;
    }
    void combinations(vector<string>& res, string temp, string digits, vector<string> dic, int level) {
        if(level == digits.size()) {
            res.push_back(temp);
            return;
        }
        int index = digits[level] - '0';
        for(int i = 0; i < dic[index].size(); i++) {
            temp.push_back(dic[index][i]);
            combinations(res, temp, digits, dic, level + 1);
            temp.pop_back();
        }
    }
};
