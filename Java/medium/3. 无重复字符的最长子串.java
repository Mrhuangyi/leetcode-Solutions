/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是 3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是 1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是 3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
*/
解法一：暴力法
枚举所有的子字符串，一个个检查相应的字符串是否含有重复的字符。检查一个字符串是否含有重复字符可以用set集合。便利整个字符串，将其中的字符一个个加入set，并且在加入之前先检查set里面是否已经有了该字符。
时间复杂度O(n^3),空间复杂度O(min(n,m))

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(allUnique(s, i, j)) {
                    res = Math.max(res, j - i);
                }
            }
        }
        return res;
    }
    public boolean allUnique(String s, int start, int end) {
        Set<Character> set = new HashSet<>();
        for(int i = start; i < end; i++) {
            Character ch = s.charAt(i);
            if(set.contains(ch)) {
                return false;
            }
            set.add(ch);
        }
        return true;
    }
}


> 上面的代码我测了下是超时的。

解法二：滑动窗口
暴力法中检查一个字符是否已经存在在子字符串里面，检查了整个字符串，时间复杂度消耗达到了O(n^2)。
利用HashSet作为滑动窗口，可以让检查的复杂度降为O(1)
我们使用 HashSet 将字符存储在当前窗口 [i,j)（最初 j=i）中。 然后我们向右侧滑动索引 j，如果它不在 HashSet 中，我们会继续滑动 j。直到 s[j] 已经存在于 HashSet 中。此时，我们找到的没有重复字符的最长子字符串将会以索引 i 开头。


class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int res = 0;
        Set<Character> set = new HashSet<Character>();
        int i = 0, j = 0;
        while(i < n && j < n) {
            if(!set.contains(s.charAt(j))) {
                set.add(s.charAt(j++));
                res = Math.max(res, j - i);
            } else {
                set.remove(s.charAt(i++));
            }
        }
        return res;
    }
}


解法三：用HashMap优化滑动窗口


class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int res = 0;
        Map<Character, Integer> map = new HashMap<>();
        int i = 0, j = 0;
        for(j = 0, i = 0; j < n; j++) {
            if(map.containsKey(s.charAt(j))) {
                i = Math.max(map.get(s.charAt(j)), i);
            }
            res = Math.max(res, j - i + 1);
            map.put(s.charAt(j), j + 1);
        }
        return res;
    }
}
