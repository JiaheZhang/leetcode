#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0] = 1;
        int index_2 = 0;
        int index_3 = 0;
        int index_5 = 0;
        int tmp_2,tmp_3,tmp_5;
        int min_val;

        for(int i = 1;i < n;i++){
            tmp_2 = dp[index_2] * 2;
            tmp_3 = dp[index_3] * 3;
            tmp_5 = dp[index_5] * 5;

            min_val = min(min(tmp_2,tmp_3),tmp_5);
            if(min_val == tmp_2) index_2++;
            if(min_val == tmp_3) index_3++;
            if(min_val == tmp_5) index_5++;
            dp[i] = min_val;
        }

        return dp[n-1];
    }
};