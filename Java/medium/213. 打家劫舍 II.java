class Solution {
    public int rob(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        if(nums.length == 1) {
            return nums[0];
        }
        int n = nums.length;
        return Math.max(rob(nums, 0, n - 2),rob(nums, 1, n - 1));
    }
    private int rob(int[] nums, int left, int right) {
        int pre2 = 0, pre1 = 0;
        for(int i = left; i <= right; i++) {
            int cur = Math.max(pre1, pre2 + nums[i]);
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
    
}
