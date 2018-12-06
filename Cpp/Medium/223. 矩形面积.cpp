/*
在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。

每个矩形由其左下顶点和右上顶点坐标表示，如图所示。

Rectangle Area

示例:

输入: -3, 0, 3, 4, 0, -1, 9, 2
输出: 45
说明: 假设矩形面积不会超出 int 的范围。

*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int resArea = 0;
        int w1 = abs(C - A);
        int h1 = abs(D - B);
        int w2 = abs(G - E);
        int h2 = abs(H - F);
        int w3 = min(C, G) - max(A, E);
        int h3 = min(D, H) - max(B, F);
        if(A >= G || B >= H || C <= E || D <= F) {
            resArea = w1 * h1 + w2 * h2;
            return resArea;
        }
        resArea = w1 * h1 + w2 * h2 - w3 * h3;
        return resArea;
    }
};
