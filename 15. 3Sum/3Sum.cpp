#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

//递归二分法查找 
int searchDivTwo(int a,int b,vector<int>& vec,int compare)
{
	if(a > b)
		return -1;
	int med = (a + b) >> 1;
	if(vec[med] == compare)
		return med;
	else
	{
		if(vec[med] < compare)
			return searchDivTwo(med + 1,b,vec,compare);
		else
			return searchDivTwo(a,med - 1,vec,compare);
	}

	
}

//Does que exist in vecAll? If does, push it
void isExistAndPush(vector<vector<int> >& vecAll,vector<int>& que) 
{
	int len = vecAll.size();
	bool isExist = false;
	if(len == 0)
	{
		vecAll.push_back(que);
		return;
	}
	for(int i = 0;i < len;i++)
	{
		if(vecAll[i][0] == que[0]) //vector比较时间花的很多，先比较第一个，这样就快了 
		{
			if(vecAll[i][1] == que[1] && vecAll[i][2] == que[2])
			{
				isExist = true;
				break;
			}
		}
	}
	if(!isExist) vecAll.push_back(que);
	
}

vector<vector<int> > threeSum(vector<int>& nums)
{
	vector<vector<int> > myVec;
	vector<int> tempVec(3);
	int len = nums.size();
	int zoreIndex;
	
	sort(nums.begin(),nums.begin()+len);
	for(int i = 0;i < len;i++)//可用二分法 
	{
		if(nums[i] >= 0)
		{
            if(nums[i] > 0)
                zoreIndex = i - 1;
            else
                zoreIndex = i;
			break;
		}
	}
	for(int i = 0;i <= zoreIndex;i++)
	{
		for(int j = zoreIndex + 1;j < len;j++)
		{
			int temp = 0 - nums[i] - nums[j];
			int index;
			index = searchDivTwo(i + 1,j - 1,nums,temp);
			if(index != -1)
			{
				tempVec[0] = nums[i];
				tempVec[2] = nums[j];
				tempVec[1] = nums[index];
				isExistAndPush(myVec,tempVec);
			}
		}
	}
	return myVec;
}


int main()
{
	return 0;
} 
