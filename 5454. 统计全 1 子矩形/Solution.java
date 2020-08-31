class Solution {
    public int numSubmat(int[][] mat) {
    	int n = mat.length;
    	if (n == 0) {
    		return 0;
    	}
    	int m = mat[0].length;
    	int[][] heights = new int[n+1][m+1];
    	int[][][] dp = new int[n+1][m+1][n+1];

    	int res = 0;

    	for (int i = 1;i <= n;i++) {
    		for (int j = 1;j <= m;j++) {
    			if (mat[i-1][j-1] == 0) {
    				continue;
    			}
    			heights[i][j] = heights[i-1][j];

    			for (int k = 1;k <= heights[i][j];k++) {
    				dp[i][j][k] = dp[i][j-1][k] + 1;
    				res += dp[i][j][k];
    			}
    		}
    	}

    	return res;
    }
}