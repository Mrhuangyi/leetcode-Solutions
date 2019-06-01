class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        for(int i = 0; i <= nums.length; i++) {
            dfs(0, temp, res, i, nums);
            
        }
        return res;
    }
    private void dfs(int start, List<Integer> temp, List<List<Integer>> res, int size, int[] nums ) {
        if(temp.size() == size) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i = start; i < nums.length; i++) {
            temp.add(nums[i]);
            dfs(i + 1, temp, res, size, nums);
            temp.remove(temp.size() - 1);
        }
    }
}
