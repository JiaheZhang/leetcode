public class s5405 {
    public int countTriplets(int[] arr) {
        int [][] dp = new int[arr.length][arr.length];
        int tmp = 0;
        int res = 0;
        for(int i = 0;i < arr.length;i++){
            tmp = 0;
            for(int j = i;j < arr.length;j++){
                tmp ^= arr[j];
                dp[i][j] = tmp;
            }
        }
        for(int i = 0;i < arr.length-1;i++){
            for(int j = i+1;j < arr.length;j++){
                for(int k = j;k < arr.length;k++){
                    if(dp[i][j-1] == dp[j][k]){
                        res++;
                    }
                }
            }
        }

        return res;
    }
}