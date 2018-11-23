/*
比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。

你可以假设版本字符串非空，并且只包含数字和 . 字符。

 . 字符不代表小数点，而是用于分隔数字序列。

例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。

示例 1:

输入: version1 = "0.1", version2 = "1.1"
输出: -1
示例 2:

输入: version1 = "1.0.1", version2 = "1"
输出: 1
示例 3:

输入: version1 = "7.5.2.4", version2 = "7.5.3"
输出: -1
*/

class Solution {
public:
   vector<string> split(const string& str, const string& pattern)
    {
        vector<string> ret;
        if (pattern.empty()) return ret;
        size_t start = 0, index = str.find_first_of(pattern, 0);
        while (index != str.npos)
        {
            if (start != index)
                ret.push_back(str.substr(start, index - start));
            start = index + 1;
            index = str.find_first_of(pattern, start);
        }
        if (!str.substr(start).empty())
            ret.push_back(str.substr(start));
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<string> V1 = split(version1, ".");
        vector<string> V2 = split(version2, ".");
 
        int len = max(V1.size(), V2.size());
        V1.insert(V1.end(), len - V1.size(), "0");
        V2.insert(V2.end(), len - V2.size(), "0");
        for (int i = 0; i < len; i++)
        {
            if (atoi(V1[i].c_str()) > atoi(V2[i].c_str())) return 1;
            if (atoi(V1[i].c_str()) < atoi(V2[i].c_str())) return -1;
        }
        return 0;
    }
};
