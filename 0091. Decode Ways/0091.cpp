#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // if(n == 1){
        //     return s[0] > '0';
        // }
        vector<int> dp(n+1,0);
        dp[0] = 1;
        if(s[0] > '0')
            dp[1] = 1;

        for(int i = 2;i <= n;i++){
            if(s[i-1] > '0'){
                dp[i] = dp[i-1];
            }
            // string sub_s = ;
            int num = stoi(s.substr(i-2,2));
            if(num <= 26 && num > 0 && s[i-2] != '0'){
                dp[i] += dp[i-2];
            }
        }


        return dp[n];
    }
};


int main(){

    Solution s;
    cout<<s.numDecodings("01");


    return 0;
}