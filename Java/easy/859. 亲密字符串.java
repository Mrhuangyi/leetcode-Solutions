给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。

 

示例 1：

输入： A = "ab", B = "ba"
输出： true
示例 2：

输入： A = "ab", B = "ab"
输出： false
示例 3:

输入： A = "aa", B = "aa"
输出： true
示例 4：

输入： A = "aaaaaaabc", B = "aaaaaaacb"
输出： true
示例 5：

输入： A = "", B = "aa"
输出： false
 

提示：

0 <= A.length <= 20000
0 <= B.length <= 20000
A 和 B 仅由小写字母构成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/buddy-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
    public boolean buddyStrings(String A, String B) {
        int n = A.length();
        int m = B.length();
        if(n != m) {
            return false;
        }
        if(A.equals(B)) {
            int[] ch = new int[26];
            for(int i = 0; i < n; i++) {
                if(ch[A.charAt(i) - 'a'] == 1) {
                    return true;
                }
                ch[A.charAt(i) - 'a']++;
            }
            return false;
        }
        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(A.charAt(i) != B.charAt(i)) {
                cnt++;
                sb.append(A.charAt(i));
                sb.append(B.charAt(i));
            }
            if(cnt > 2) {
                return false;
            }
        }
        return sb.charAt(0) == sb.charAt(3) && sb.charAt(1) == sb.charAt(2);
    }
}
