class Solution {
    private int n;
    public int findCircleNum(int[][] M) {
        n = M.length;
        int circleNum = 0;
        boolean[] hasVisited = new boolean[n];
        for(int i = 0; i < n; i++) {
            if(!hasVisited[i]) {
                dfs(M, i, hasVisited);
                circleNum++;
            }
        }
        return circleNum;
    }
    private void dfs(int[][] M, int i, boolean[] hasVisited) {
        hasVisited[i] = true;
        for(int k = 0; k < n; k++) {
            if(M[i][k] == 1 && !hasVisited[k]) {
                dfs(M, k, hasVisited);
            }
        }
    }
}
