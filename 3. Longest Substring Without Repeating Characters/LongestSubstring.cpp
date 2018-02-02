#include<iostream>
#include<map>
#include<string>
using namespace std;


class Solution 
{
	public:
	    int lengthOfLongestSubstring(string s)
		{
			map<char,int> mymap; 
			int head = 0;
			int tail = 0;
			int len = 0;
			int i = 0;
			map<char,int>::iterator it;
			//注释内的方法效率太低 接近O(n^2) 
			/*for(i = 0;i < s.size();i++)
			{
				if(mymap.count(s[i]) == 1)
				{
					
					tail = i;
					if(tail - head > len) len = tail - head;
					head = mymap[s[i]] + 1;
					mymap.clear();
					for(int j = head;j <= tail;j++)
					{
						mymap[s[j]] = j;
					}
					
				}
				else
				{
					mymap[s[i]] = i;
				}
			}
			tail = i;
			if(tail - head > len) len = tail - head;
			*/
			for(i = 0;i < s.size();i++)
			{
				it = mymap.find(s[i]);
				if(it != mymap.end() && it->second >= head)
				{
					tail = i;
					if(tail - head > len) len = tail - head;
					head = mymap[s[i]] + 1;
					
				}
					mymap[s[i]] = i;
			}
			tail = i;
			if(tail - head > len) len = tail - head;
	        return len;
	    }
};


int main()
{
	Solution s;
	string str = "abba";
	cout<<s.lengthOfLongestSubstring(str);
	return 0;
}
