#include<iostream>
#include<vector>
using namespace std;

 class solution
 {
 	public:
	 vector<int> twoSum(vector<int>& nums, int target)
	 {
	 	vector<int> result;
	 	for(int i = 0;i < nums.capacity();i++)
	 	{
	 		for(int j = i + 1;j < nums.capacity();j++)
	 		{
	 			if(nums[i] + nums[j] == target)
	 			{
	 				result.push_back(i);
	 				result.push_back(j);
	 				return result;
	 			}
	 		}
	 		
	 	}
	 	return result;
	 }
 };

 int main()
 {
 	int arr[10] = {3,2,4};
 	vector<int> a(arr,arr+3);
 	vector<int> result(2);
 	solution solution1;
 	result = solution1.twoSum(a,6);
 	cout<<result.at(0);
 	cout<<result.at(1);
 }
 

