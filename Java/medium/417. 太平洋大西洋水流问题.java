class Solution {
    private int m, n;
    private int[][] matrix;
    private int[][] direction = {{0, 1}, {0, -1}, { 1, 0}, {-1, 0}};
    public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> res = new ArrayList<>();
        if(matrix == null || matrix.length == 0) {
            return res;
        }
        m = matrix.length;
        n = matrix[0].length;
        this.matrix = matrix;
        boolean[][] canReachP = new boolean[m][n];
        boolean[][] canReachA = new boolean[m][n];
        for(int i = 0; i < m; i++) {
            dfs(i, 0, canReachP);
            dfs(i, n - 1, canReachA);
        }
        for(int i = 0; i < n; i++) {
            dfs(0, i, canReachP);
            dfs(m - 1, i, canReachA);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(canReachP[i][j] && canReachA[i][j]) {
                    res.add(new int[]{i, j});
                }
            }
        }
        return res;
    }
    private void dfs(int r, int c, boolean[][] canReach) {
        if(canReach[r][c]) {
            return ;
        }
        canReach[r][c] = true;
        for(int[] d : direction) {
            int nextR = d[0] + r;
            int nextC = d[1] + c;
            if(nextR < 0 || nextR >= m || nextC < 0 || nextC >= n || matrix[r][c] > matrix[nextR][nextC]) {
                continue;
            }
            dfs(nextR, nextC, canReach);
        }
    }
}
