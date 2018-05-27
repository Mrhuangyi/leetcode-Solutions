请编写一个函数，其功能是将输入的字符串反转过来。

示例：

输入：s = "hello"
返回："olleh"

class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(),s.end());
        return s;
    }
};

class Solution {
public:
    string reverseString(string s) {
      string res;
		for (int nIdx = 0; nIdx < s.length(); nIdx++)
		{
			res += s[s.length() - nIdx - 1];
		}
		return res;
    }
};
