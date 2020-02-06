请编写一个函数，其功能是将输入的字符串反转过来。

示例：

输入：s = "hello"
返回："olleh"

写法一：
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(),s.end());
        return s;
    }
};

写法二：
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

写法三：
class Solution {
public:
    void helper(vector<char>& s, int left, int right) {
        if(left >= right) {
            return ;
        }
        swap(s[left], s[right]);
        left++;
        right--;
        helper(s, left, right);
    }
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }
};

写法四：
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        char temp;
        while(i < j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};
