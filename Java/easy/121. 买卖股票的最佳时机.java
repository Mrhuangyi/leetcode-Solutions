class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n == 0) {
            return 0;
        }
        int beforeMin = prices[0];
        int max = 0;
        for(int i = 1; i < n; i++) {
            if(beforeMin > prices[i]) {
                beforeMin = prices[i];
            } else {
                max = Math.max(max, prices[i] - beforeMin);
            }
        }
        return max;
    }
}
