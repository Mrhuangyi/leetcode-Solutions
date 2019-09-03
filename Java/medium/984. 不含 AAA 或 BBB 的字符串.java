给定两个整数 A 和 B，返回任意字符串 S，要求满足：

S 的长度为 A + B，且正好包含 A 个 'a' 字母与 B 个 'b' 字母；
子串 'aaa' 没有出现在 S 中；
子串 'bbb' 没有出现在 S 中。
 

示例 1：

输入：A = 1, B = 2
输出："abb"
解释："abb", "bab" 和 "bba" 都是正确答案。
示例 2：

输入：A = 4, B = 1
输出："aabaa"
 

提示：

0 <= A <= 100
0 <= B <= 100
对于给定的 A 和 B，保证存在满足要求的 S。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-without-aaa-or-bbb
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
    public String strWithout3a3b(int A, int B) {
        StringBuilder sb = new StringBuilder();
        while(A > 0 && B > 0) {
            if(A > B) {
                sb.append("aab");
                A -= 2;
                B -= 1;
            } else if(A == B) {
                for(int i = 0; i < A; i++) {
                    sb.append("ab");
                }
                A = 0;
                B = 0;
            } else {
                sb.append("bba");
                A -= 1;
                B -= 2;
            }
        }
        if( A == 0) {
            for(int i = 0; i < B; i++) {
                sb.append("b");
            }
        } else {
            for(int i = 0; i < A; i++) {
                sb.append("a");
            }
        }
        return sb.toString();
    }
}
