#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void traceBack(vector<int>& nums, int left){
        if(left == nums.size()){
            result.push_back(nums);
        }

        for(int i = left;i < nums.size();i++){
            swap(nums[i],nums[left]);
            traceBack(nums, left+1);
            swap(nums[i],nums[left]);


        }



    }
    vector<vector<int>> permute(vector<int>& nums) {
        traceBack(nums,0);
        return result;
    }
};