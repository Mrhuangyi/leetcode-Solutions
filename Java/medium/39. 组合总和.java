class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> combinations = new ArrayList<>();
        backtrack(new ArrayList<>(), combinations, 0, target, candidates);
        return combinations;
    }
    private void backtrack(List<Integer> tempCombination, List<List<Integer>> combinations, int start, int target, final int[] candidates) {
        if(target == 0) {
            combinations.add(new ArrayList<>(tempCombination));
            return ;
        }
        for(int i = start; i < candidates.length; i++) {
            if(candidates[i] <= target) {
                tempCombination.add(candidates[i]);
                backtrack(tempCombination, combinations, i, target - candidates[i], candidates);
                tempCombination.remove(tempCombination.size() - 1);
            }
        }
    }
}
