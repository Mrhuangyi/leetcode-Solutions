class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> combinations = new ArrayList<>();
        List<Integer> combineList = new ArrayList<>();
        backtrack(combineList, combinations, 1, k, n);
        return combinations;
    }
    private void backtrack(List<Integer> combineList, List<List<Integer>> combinations, int start, int k, final int n) {
        if(k == 0) {
            combinations.add(new ArrayList<>(combineList));
            return;
        }
        for(int i = start; i <= n - k + 1; i++) {
            combineList.add(i);
            backtrack(combineList, combinations, i + 1, k - 1, n);
            combineList.remove(combineList.size() - 1);
        }
    }
}
