class Solution {
    public int maxProfit(int[] prices) {
        int proFir = 0;
        int proSec = 0;
        int minFir = Integer.MAX_VALUE;
        int minSec = Integer.MAX_VALUE;

        for (int p : prices) {
            minFir = Math.min(minFir, p);
            proFir = Math.max(proFir, p - minFir);

            minSec = Math.min(minSec, p - proFir);
            proSec = Math.max(proSec, p - minSec);
        }
        return proSec;
    }
}