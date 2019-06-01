class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> paths = new ArrayList<>();
        dfs(k, n, 1, paths, res);
        return res;
    }
    private void dfs(int k, int n, int start, List<Integer> temp, List<List<Integer>> res) {
        if(k == 0 && n == 0) {
            res.add(new ArrayList<>(temp));
            return;
        }
        if(k == 0 || n == 0) {
            return;
        }
        for(int i = start; i <= 9; i++) {
            temp.add(i);
            dfs(k - 1, n - i, i + 1, temp, res);
            temp.remove(temp.size() - 1);
        }
    }
}
