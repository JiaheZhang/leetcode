#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp;
        
        dp.push_back(triangle[0]);

        // dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j]

        vector<int> dp_line;
        int max_num = 99999999;
        for(int i = 1;i < triangle.size();i++){
            dp_line.clear();
            dp_line.push_back(dp[i-1][0] + triangle[i][0]);
            for(int j = 1;j < triangle[i].size()-1;j++){
                dp_line.push_back(min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j]);
            }
            dp_line.push_back(dp[i-1][triangle[i].size()-2] + triangle[i][triangle[i].size()-1]);

            dp.push_back(dp_line);
        }
        
        for(int d : dp[dp.size()-1]){
            if(d < max_num){
                max_num = d;
            }
        }
        return max_num;

    }
};


int main(){

    Solution s;

    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<s.minimumTotal(triangle);
    return 0;
}