class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        boolean[] isVisited = new boolean[nums.length];
        for(int i = 0; i <= nums.length; i++) {
            dfs(0, temp, res, isVisited, i, nums);
        }
        return res;
    }
    private void dfs(int start, List<Integer> temp, List<List<Integer>> res, boolean[] isVisited, int size, int[] nums) {
        if(temp.size() == size) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i = start; i < nums.length; i++) {
            if(i != 0 && nums[i] == nums[i - 1] && !isVisited[i - 1]) {
                continue;
            }
            temp.add(nums[i]);
            isVisited[i] = true; 
            dfs(i + 1, temp, res, isVisited, size, nums);
            isVisited[i] = false;
            temp.remove(temp.size() - 1);
        }
    }
}
