#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

vector<string> letterCombinations(string digits)
{
	int len = digits.size();
	if (len == 0)
		return{};

	string value[255];
	value['2'] = "abc";
	value['3'] = "def";
	value['4'] = "ghi";
	value['5'] = "jkl";
	value['6'] = "mno";
	value['7'] = "pqrs";
	value['8'] = "tuv";
	value['9'] = "wxyz";
	value['*'] = "+";
	value['0'] = " ";

	vector<string> vec;
	for (int i = 0; i < value[digits[0]].size(); i++)
	{
		//这个地方比较坑
		stringstream ss;
		ss << value[digits[0]][i];
		vec.push_back(ss.str());
	}

	for (int i = 1; i < len; i++)
	{
		int lenStr = value[digits[i]].size();
		int lenVec = vec.size();
		vector<string> tempVec;
		tempVec = vec;

		for (int k = 0; k < lenVec; k++)
		{
			vec[k] += value[digits[i]][0];
		}
		for (int j = 1; j < lenStr; j++)
		{
			vec.insert(vec.end(), tempVec.begin(), tempVec.end()); //复制 并且整段移过来  移lenStr.size() - 1次
			for (int k = 0; k < lenVec; k++)
			{
				vec[k + j * lenVec] += value[digits[i]][j];//添上新的字符
			}
		}

	}
	return vec;
}

int main()
{
	string s = "22";
	vector<string> v;
	v = letterCombinations(s);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	int a;
	cin >> a;
	return 0;
}