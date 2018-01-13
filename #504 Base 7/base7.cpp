#include<iostream>
using namespace std;
 
string convertToBase7(int num)
{
	int max7 = 282475249;
	int k = 0;
	string s;
	string result;
	
	if(num == 0) return "0";
	if(num < 0) 
	{
		result += '-';
		num  = -num;
	}
	for(int i = 10;i>=0;i--)
	{
		int temp = num / max7;
		num = num % max7;
		s += ('0' + temp);
		max7 /= 7;
	}

	s += '\0';
	
	for(int i = 0;i<s.size();i++)
	{
		if(s[i] != '0')
		{
			result += s.substr(i,s.size() - i);
			break;
		}
	}
	return result;
}

int main()
{
	int k = -2402; 
	cout<<convertToBase7(k);
	return 0;
}
