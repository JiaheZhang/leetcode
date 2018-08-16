#include<iostream>
#include<vector>
using namespace std;

string mylongestCommonPrefix(vector<string>::iterator it,int len)
{
	if(len == 1)  return *it;
	if(len == 0)  return "\0";
	
	string comStr1,comStr2;
	string newComStr;
	
	comStr1 = mylongestCommonPrefix(it,len / 2);//递归调用 左右分为两段 
	comStr2 = mylongestCommonPrefix(it + len / 2,len - len / 2);
	int minlen;
	minlen = min(comStr1.size(),comStr2.size());
	
	for(int i = 0;i < minlen;i++)
	{
		if(comStr1[i] == comStr2[i])
		{
			newComStr += comStr1[i];
		}
		else break;
	}
	newComStr += '\0';
	return newComStr;
}

string longestCommonPrefix(vector<string>& strs)
{
	int len = strs.size();
	return mylongestCommonPrefix(strs.begin(),len);
}
/*注释内的有额外的赋值操作 改为用iterator 
string longestCommonPrefix(vector<string>& strs)
{
	
	int len = strs.size();
	
	if(len == 1)  return strs[0];
	if(len == 0)  return "\0";
	
	vector<string> strs1;
	vector<string> strs2;
	
	vector<string>::iterator it = strs.begin();
	for(int i = 0;i < len;i++)
	{
		if(i < (len / 2)) strs1.push_back(*it);
		else strs2.push_back(*it);
		it++;
	}
	
	string comStr1,comStr2;
	string newComStr;
	comStr1 = longestCommonPrefix(strs1);
	comStr2 = longestCommonPrefix(strs2);
	int minlen;
	minlen = min(comStr1.size(),comStr2.size());
	
	for(int i = 0;i < minlen;i++)
	{
		if(comStr1[i] == comStr2[i])
		{
			newComStr += comStr1[i];
		}
		else break;
	}
	newComStr += '\0';
	return newComStr;
}
*/
int main()
{
	vector<string> s(2);
	s[0] = "c";
	s[1] = "c";
	cout<<longestCommonPrefix(s);
	return 0;
}
