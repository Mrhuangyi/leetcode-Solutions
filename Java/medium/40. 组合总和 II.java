class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> combinations = new ArrayList<>();
        Arrays.sort(candidates);
        backtrack(new ArrayList<>(), combinations, new boolean[candidates.length], 0, target, candidates);
        return combinations;
    }
    private void backtrack(List<Integer> tempCombination, List<List<Integer>> combinations, boolean[] hasVisited, int start, int target, final int[] candidates) {
        if(target == 0) {
            combinations.add(new ArrayList<>(tempCombination));
            return;
        }
        for(int i = start; i < candidates.length; i++) {
            if(i != 0 && candidates[i] == candidates[i - 1] && !hasVisited[i - 1]) {
                continue;
            }
            if(candidates[i] <= target) {
                tempCombination.add(candidates[i]);
                hasVisited[i] = true;
                backtrack(tempCombination, combinations, hasVisited, i + 1, target - candidates[i], candidates);
                hasVisited[i] = false;
                tempCombination.remove(tempCombination.size() - 1);
            }
        }
    }
}
