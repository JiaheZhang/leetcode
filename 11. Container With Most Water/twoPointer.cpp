#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height)
{
	int len = height.size();
	int maxArea = 0;
	int i,j;
	i = 0;
	j = len - 1;
	while(i <= j)
	{
		int temp = 0;
		if(height[i] >= height[j])
		{
			temp = height[j] * (j - i);
			if(temp > maxArea)  maxArea = temp;
			--j;
		}
		else
		{
			temp = height[i] * (j - i);
			if(temp > maxArea)  maxArea = temp;
			++i;
		}
	}
	return maxArea;
}
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	cout<<maxArea(v);
	return 0;
} 
