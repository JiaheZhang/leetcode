class Solution {
    public int maxProfit(int[] prices) {
        int sum = 0;
        int len = prices.length;
        if (len <= 1) {
        	return 0;
        }
        int minVal = prices[0];
        for (int i = 1; i < len; ++i) {
        	if (prices[i] - prices[i - 1] >= 0) {
        		if (i == len - 1) {
        			sum += (prices[i - 1] - minVal);
        		}
        		continue;
        	} else {
        		if (prices[i - 1] > minVal) {
        			sum += (prices[i - 1] - minVal);
        		}
        		minVal = prices[i];
        	}
        }

        return sum;
    }
}