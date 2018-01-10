#include<iostream>
#include<vector>
using namespace std; 
class Solution
{
	public:
	    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
		{
			double result;
			int m = 0;
			int lenNums1 = nums1.size();
			int lenNums2 = nums2.size();
			vector<int> mynum;
			int i = 0;
			int j = 0;
			//这个方法太慢了 根本不需要赋值到一个新的数组 直接找到 len1 + len2 的中间就行 O(n)
			while(i < lenNums1 || j < lenNums2)
			{
				if(i < lenNums1 && j < lenNums2)
				{
					if(nums1[i] <= nums2[j])
					{
						mynum.push_back(nums1[i]);
						cout<<nums1[i]<<endl;
						i++;
					}
					else
					{
						mynum.push_back(nums2[j]);
						cout<<nums2[i]<<endl;
						j++;
					}
				}
				else
				{
					if(i < lenNums1)
					{
						mynum.push_back(nums1[i]);
						cout<<nums1[i]<<endl;
						i++;
					}
					if(j < lenNums2)
					{
						mynum.push_back(nums2[j]);
						cout<<nums2[j]<<endl;
						j++;
					}
				}
			}
			m = mynum.size();
			if(m % 2 == 0)
			{
				m /= 2;
				result = double((mynum[m] + mynum[m - 1]) / 2.0);
			}
			else
			{
				m /= 2;
				result =  mynum[m];
			}
			 
			return result;
	    }
};

int main()
{
	Solution s;
	vector<int> n1;
	vector<int> n2;
	for(int i = 0;i < 2;i++)
	{
		n1.push_back(i+1);
	}
	for(int i = 3;i < 5;i++)
	{
		n2.push_back(i);
	}
	cout<<s.findMedianSortedArrays(n1,n2);
	
	return 0;
}
