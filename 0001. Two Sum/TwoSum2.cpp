#include<iostream>
#include<vector>
#include<map> 
using namespace std;

 class solution
 {
 	public:
	 vector<int> twoSum(vector<int> nums, int target)
	 {
	 	map<int,int> myMap;
	 	vector<int> v(2);
	 	int rest = 0;
	 	for(int i =0;i < nums.size();i++)
	 	{
	 		myMap[nums[i]] = i;
	 	}
	 	for(int i = 0;i < nums.size();i++)
	 	{
	 		rest = target - nums[i];
	 		if(myMap.count(rest) > 0) 
	 		{
	 			if(myMap[rest] != i)
	 			{
	 				v[0] = i;
		 			v[1] = myMap[rest];
		 			return v;
	 			}
	 			
	 		}
			 
	 	}
	 	return v;
	 }
 };

 int main()
 {
 	int arr[] = {3,2,4};
 	vector<int> a(arr,arr+3);
 	vector<int> result(2);
 	solution solution1;
 	result = solution1.twoSum(a,6);
 	cout<<result.at(0);
 	cout<<result.at(1);
 }
