#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_p = 0;
        int min_p = 0xffff;

        for(int i = 0;i < prices.size();i++){
            if(prices[i] < min_p){
                min_p = prices[i];
            }
            else if(prices[i] - min_p > max_p){
                max_p = prices[i] - min_p;
            }
        }

        return max_p;
    }
};