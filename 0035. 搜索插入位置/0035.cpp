#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        if(nums.back() < target) return nums.size();
        int left = 0,right = nums.size()-1;
        int mid;
        while(left < right){
            mid = (left + right) >> 1;
            if(nums[mid] >= target){
                if(nums[mid] == target) return mid;
                right = mid;

            }
            else{
                left = mid+1;
            }
        }

        return left;
    }
};