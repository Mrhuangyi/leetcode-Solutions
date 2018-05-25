给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。


用两个HashMap维护字符的映射关系，时间复杂度O(n)，空间复杂度O(n)。

class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()) return false;
        final Map<Character,Character> map1 = new HashMap<>();
        final Map<Character,Character> map2 = new HashMap<>();
        for(int i=0;i<s.length();i++){
            final char c1 = s.charAt(i);
            final char c2 = t.charAt(i);
            if(map1.containsKey(c1)){
                if(map1.get(c1)!=c2) return false;
            }else{
                map1.put(c1,c2);
            }
            if(map2.containsKey(c2)){
                if(map2.get(c2)!=c1) return false;
            }else{
                map2.put(c2,c1);
            }
        }
        return true;
    }
}
