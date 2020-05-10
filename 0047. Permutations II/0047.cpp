#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void traceBack(vector<int>& nums, int left){
        if(left == nums.size()){
            res.push_back(nums);
        }

        unordered_set<int> my_set;
        for(int i = left;i < nums.size();i++){
            if(my_set.count(nums[i]) > 0){
                continue;
            }
            my_set.insert(nums[i]);
            // if(i != left && nums[i] == nums[left]) continue;
            swap(nums[i],nums[left]);
            traceBack(nums, left+1);
            swap(nums[i],nums[left]);


        }



    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        traceBack(nums,0);
        return res;
    }
};

int main(){
    vector<int> a={1,2,3};

    Solution s;

    s.permuteUnique(a);

    return 0;
}