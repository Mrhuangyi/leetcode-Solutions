初始位置 (0, 0) 处有一个机器人。给出它的一系列动作，判断这个机器人的移动路线是否形成一个圆圈，换言之就是判断它是否会移回到原来的位置。

移动顺序由一个字符串表示。每一个动作都是由一个字符来表示的。机器人有效的动作有 R（右），L（左），U（上）和 D（下）。输出应为 true 或 false，表示机器人移动路线是否成圈。

示例 1:

输入: "UD"
输出: true
示例 2:

输入: "LL"
输出: false

class Solution {
public:
    bool judgeCircle(string moves) {
        int L=0,R=0,U=0,D=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                L++;
            }else if(moves[i]=='R'){
                R++;
            }else if(moves[i]=='U'){
                U++;
            }else if(moves[i]=='D'){
                D++;
            }
        }
        if(L==R&&U==D){
            return true;
        }else{
            return false;
        }
    }
};
