class Solution {
    public int singleNonDuplicate(int[] nums) {
        int res = 0;
        for(int i = 0; i < nums.length; i++) {
            res = nums[i] ^ res;
        }
        return res;
    }
}
