给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int lens = s.size();
        int lenp = p.size();
        if(lens == 0 || lenp == 0 || lens < lenp) {
            return res;
        }
        int a[26] = {0};
        for(int i = 0; i < lenp; i++) {
            a[p[i] - 'a']++;
        }
        for(int i = 0; i < lenp - 1; i++) {
            a[s[i] - 'a']--;
        }
        for(int i = 0; i < lens - lenp + 1; i++) {
            a[s[i + lenp - 1] - 'a']--;
            if(isZero(a)) {
                res.push_back(i);
            }
            a[s[i] - 'a']++;
        }
        return res;
    }
private:
    bool isZero(int a[]) {
    for(int i = 0; i < 26; i++) {
        if(a[i] != 0) {
            return false;
        }
    }
    return true;
}
};
