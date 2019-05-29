class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> resList = new ArrayList<>();
        boolean[] hasVisited = new boolean[nums.length];
        backtrack(resList, res, hasVisited, nums);
        return res;
    }
    private void backtrack(List<Integer> resList, List<List<Integer>> res, boolean[] visited, final int[] nums) {
        if(resList.size() == nums.length) {
            res.add(new ArrayList<>(resList));
            return ;
        }
        for(int i = 0; i < visited.length; i++) {
            if(visited[i]) {
                continue;
            }
            visited[i] = true;
            resList.add(nums[i]);
            backtrack(resList, res, visited, nums);
            resList.remove(resList.size() - 1);
            visited[i] = false;
        }
    }
}
