class Solution {
    public void sortColors(int[] nums) {
        int left = 0;
        int middle = 0;
        int right = nums.length - 1;
        while(middle <= right) {
            if(nums[middle] == 0) {
                swap(nums, left, middle);
                left++;
                middle++;
            } else if(nums[middle] == 2) {
                swap(nums, middle, right);
                right--;
            } else {
                middle++;
            }
        }
    }
    private void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
