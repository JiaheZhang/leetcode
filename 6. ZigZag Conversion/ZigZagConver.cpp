#include<iostream>
#include<string>
using namespace std;

class Solution
{
	public:
	    static string convert(string s, int numRows)
		{
	        string mys[numRows];
	        int r[numRows];//����ÿһ�еļ�� 
	        int r1 = (numRows << 1) - 2;
	        int len = s.size();
	        int flag = 0;
	        string result;
	        
	        if(numRows == 1) return s;
	        
	        for(int i = 0;i < numRows - 1;i++)
	        {
	        	r[i] = r1 - (i << 1); //ÿ�еݼ�2 
	        }
	        r[numRows - 1] = r[0];//��һ�������һ����ͬ 
	        
	        int i = 0;
	        int j = 0;
	        
	        while(j < len) //��һ�� 
	        {
	        	mys[0] += s[j];
	        	j += r[0];
	        }

	        j = 0;
	        while(numRows - 1 + j < len)//���һ�� 
	        {
	        	mys[numRows - 1] += s[numRows - 1 + j];
				j += r[0];
	        }
	        //mys[numRows - 1] += '\n';
	        
	        for(i = 1;i < numRows - 1;i++)
	        {
	        	j = i;
	        	flag = 0;
	        	while(j < len)
				{
					if(flag == 0)
					{
						flag = 1;
						mys[i] += s[j];
						j = j + r[i];
					}
					else
					{
						flag = 0;
						mys[i] += s[j];
						j = j + r1 - r[i];
					}
				}
				//mys[i] += '\n';
	        }
	         for(i = 0;i < numRows;i++)
	         {
	         	result += mys[i];
	         }
	         result += '\0';
	         return result;
	    }
};

int main()
{
	string s = "a";
	cout<<Solution::convert("asdfg",4);
	return 0;
} 
