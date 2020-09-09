class Solution {
    public int maxSubArray(int[] nums) {
    	int len = nums.length;
    	int[] dp = new int[len + 1];
    	int res = Integer.MIN_VALUE;
    	dp[0] = 0;
    	for (int i = 0; i < len; ++i) {
    		dp[i + 1] = Math.max(dp[i] + nums[i], nums[i]);
    		res = Math.max(res, dp[i + 1]);
    	}

    	return res;

    }
}