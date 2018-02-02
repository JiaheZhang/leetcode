#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	int len = nums.size();
	int head = 1;
	int tail = len - 1;
	int myTarget = 0;
	int closestTarget = 0;
	int minValue = 9999999;//initial value 

	sort(nums.begin(), nums.end());

	for (int i = 0; i < len; i++)
	{
		myTarget = target - nums[i];
		head = i + 1;
		tail = len - 1;
		while (head < tail)
		{
			int sum = nums[head] + nums[tail];
			if (abs(sum - myTarget) < minValue)
			{
				minValue = abs(sum - myTarget);
				closestTarget = sum + nums[i];
			}

			if (sum < myTarget)
				head++;
			else
			if (sum>myTarget)
				tail--;
			else
				return target;//
		}

	}
	return closestTarget;

}

int main()
{
	cout << "s" << endl;
	return 0;
}
