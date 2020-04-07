#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        // if(n == 3) return 2;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;

        for(int i = 4;i <= n;i++){
            for(int j = 2;j < i;j++){
                // dp[i] = max(dp[i],max(j*(i-j), j*dp[i-j]));
                dp[i] = max(dp[i],max(j,dp[j]) * max(i-j,dp[i-j]));
                // max(j*(i-j), j*maxArr[i-j])
            }
        }
        return dp[n];
    }
};


int main(){
    Solution s;
    cout<<s.integerBreak(100);
    return 0;
}