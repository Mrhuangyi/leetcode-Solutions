class Solution {
public:
    bool isArmstrong(int N) {
        int num = 0;
        int temp1 = N;
        while(N) {
            N = N / 10;
            num++;
        }
        N = temp1;
        int temp = 0, sum = 0;
        while(N) {
            temp = N % 10;
            sum += pow(temp, num);
            N = N / 10;
        }
        return sum == temp1;
    }
};
