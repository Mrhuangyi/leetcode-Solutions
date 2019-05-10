class Solution {
    public boolean judgeSquareSum(int c) {
        int i = 0;
        int j = (int)Math.sqrt(c);
        while(i <= j) {
            int powSum = i * i + j * j;
            if(powSum == c) {
                return true;
            } else if(powSum < c) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
}
