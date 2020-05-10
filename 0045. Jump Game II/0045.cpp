#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;

        int max_index = 0;
        int tmp_max = 0;
        int times = 0;

        for(int i = 0;i < nums.size()-1;i++){
            tmp_max = max(tmp_max,nums[i]+i);
            if(i == max_index){
                max_index = tmp_max;
                times++;
                if(max_index >= nums.size()-1) return times;
            }
        }
        return times;
    }
};

/*
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i < n;i++){
            for(int j = i - 1;j >= 0;j--){
                if(nums[j] >= i - j){
                    dp[i] = min(dp[j] + 1,dp[i]);
                }
            }
        }


        return dp[n-1];
    }
};
*/