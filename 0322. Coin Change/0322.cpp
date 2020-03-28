#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    const int max_init = 9999999;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,max_init);
        dp[0] = 0;
        
        for(int i = 1;i <= amount;++i){
            for(int j = 0;j < coins.size();++j){
                if(i - coins[j] >= 0){
                    dp[i] = min(dp[i - coins[j]]+1,dp[i]);
                }
            }
        }
        
        return dp[amount] == max_init ? -1:dp[amount];
    }
};