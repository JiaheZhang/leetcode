#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int left = 0;
        int right = nums.size();
        int mid;

        while (left < right){
            if(left + 1 == right) return nums[left] > nums[right] ? left : right;
            mid = (left + right) >> 1;
            if(nums[mid] < nums[mid+1]) left = mid;
            else right = mid;
        }
        return left;
    }
};