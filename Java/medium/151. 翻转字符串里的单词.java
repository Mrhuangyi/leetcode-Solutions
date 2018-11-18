/*
给定一个字符串，逐个翻转字符串中的每个单词。

示例:  

输入: "the sky is blue",
输出: "blue is sky the".
说明:

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。
*/

public class Solution {
    public String reverseWords(String s) {
        if(s.length() == 0 || s == null){
            return "";
        }
        String[] array = s.split(" ");
        StringBuilder sb = new StringBuilder();
        
        for(int i = array.length - 1; i >= 0; i--){
            if(!array[i].equals("")) {
                if (sb.length() > 0) {
                    sb.append(" ");
                }
                
                sb.append(array[i]);
            }
        }
        return sb.toString();
        
    }
}
