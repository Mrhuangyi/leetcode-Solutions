给定一个字符串来代表一个学生的出勤纪录，这个纪录仅包含以下三个字符：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场
如果一个学生的出勤纪录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。

你需要根据这个学生的出勤纪录判断他是否会被奖赏。

示例 1:

输入: "PPALLP"
输出: True
示例 2:

输入: "PPALLL"
输出: False

class Solution {
public:
    bool checkRecord(string s) {
        int num1 = 0,num2 = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A'){
                num1++;
            }
            if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L'){
                num2++;
            }
        }
        if(num1<=1&&num2==0){
            return true;
        }else{
            return false;
        }
    }
};
