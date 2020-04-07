#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int cur_max,pre_max = nums[0];
        int cur_min,pre_min = nums[0];

        int max_val = nums[0];

        for(int i = 1;i < n;i++){
            cur_max = max(max(pre_max*nums[i],pre_min*nums[i]),nums[i]);
            cur_min = min(min(pre_max*nums[i],pre_min*nums[i]),nums[i]);

            pre_max = cur_max;
            pre_min = cur_min;

            max_val = max(pre_max,max_val);
        }

        return max_val;
    }
};

int main(){
    Solution s;
    vector<int> v = {2,3,-2,4};
    cout<<s.maxProduct(v);

    return 0;
}