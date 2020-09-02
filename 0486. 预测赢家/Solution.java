class Solution {
    public boolean PredictTheWinner(int[] nums) {
    	return helper(nums, 0, nums.length-1, 1) >= 0;
    }

    private int helper(int[] nums, int left, int right, int turn) {
    	if (left == right) {
    		return nums[left] * turn;
    	}
    	int leftScore = nums[left] * turn + helper(nums, left + 1, right, -turn);
    	int rightScore = nums[right] * turn + helper(nums, left, right - 1, -turn);
    	return Math.max(leftScore * turn, rightScore * turn) * turn;
    }
}

//dp
//dp[i][j] max nums[i...j] 
class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n-1] >= 0;
    }
}