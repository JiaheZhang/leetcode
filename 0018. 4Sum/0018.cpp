/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]



*/





#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(),nums.end());

    for(int i = 0;i < n-3;i++)
    {
        //one point at the start of nums
        if(i != 0 && nums[i] == nums[i-1]) continue;// exclude the same answer
        if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;//optimize the time
        for(int j = i + 1;j < n-2;j++)
        {
            //another point at i+1 
            if(j != i + 1 && nums[j] == nums[j-1]) continue;// exclude the same answer
            int left = j + 1;
            int right = n - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum < target) left++;
                else if(sum > target) right--;
                else
                {
                    result.push_back({nums[i],nums[j],nums[left],nums[right]});

                    // exclude the same answer
                    do{left++;}while(nums[left] == nums[left-1]);
                    do{right--;}while(nums[right] == nums[right+1]);
                }

            }
        }
    }








    return result;

}


int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result;

    result = fourSum(nums,target);
    for(int i = 0;i < result.size();i++)
    {
        cout<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<" "<<result[i][3]<<" "<<endl;
    }

    system("pause");
    return 0;
}
