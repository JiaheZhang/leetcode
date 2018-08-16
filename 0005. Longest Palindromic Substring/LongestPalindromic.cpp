#include<iostream>
#include<string>

using namespace std;

class Solution
{
	public:
	    static string longestPalindrome(string s) 
		{
	        bool p[1000][1000] = {false};
	        int len = s.length();
	        int maxLen = 1;//initial value
	        int head = 0;
	        for(int i = 0;i < len;i++)
	        {
	        	p[i][i] = true;
	        }
	        for(int i = 0;i < len;i++)
	        {
	        	if(s[i] == s[i + 1])
	        	{
	        		p[i][i + 1] = true;
	        		if(maxLen < 2) //when maxLen = 2
	        		{
	        			maxLen = 2;
		        		head = i;
	        		}
	        		
	        	}
	        }
	        
	        for(int i = 3;i <= len;i++)
	        {
	        	if(i % 2 == 0)
	        	{
	        		for(int j = 0;j < len;j++)
	        		{
	        			if(j - i/2 + 1 < 0 || j + i/2 >= len) continue; //if index out of range of s, pass
	        			else
	        			{
	        				if(p[j - i/2 + 2][j + i/2 -1] == true && s[j - i/2 + 1] == s[j + i/2])
		        			{
		        				p[j - i/2 + 1][j + i/2] = true;
		        				if(i > maxLen)
		        				{
		        					maxLen = i;
		        					head = j - i/2 + 1;
		        				}
		        			}
		        			else
		        			{
		        				p[j - i/2 + 1][j + i/2] = false;
		        			}
	        			}
	        		}
	        	}
	        	else
	        	{
	        		for(int j = 0;j < len;j++)
	        		{
	        			if(j - i/2 < 0 || j + i / 2 >= len) continue;//if index out of range of s, pass
	        			else
	        			{
	        				//p[i][i] == true and s[i - 1] == s[i + 1] 
	        				//then p[i - 1][i + 1] = true
	        				if(p[j - i/2 + 1][j + i/2 - 1] == true && s[j - i/2] == s[j + i/2])
		        			{
		        				p[j - i/2][j + i/2] = true;
		        				if(i > maxLen)
		        				{
		        					maxLen = i;
		        					head = j - i / 2;
		        				}
		        			}
		        			else
		        			{
		        				p[j - i/2][j + i/2] = false;
		        			}
	        			}
	        		}
	        	}
	        	
	        }
	        return s.substr(head,maxLen);
	    }
}; 

int main()
{
	string s = "asdffdsa";
	cout<<Solution::longestPalindrome(s);
	return 0;
}
