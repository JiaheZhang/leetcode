#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void _createPreOrder(TreeNode* &r,int ch[],int &i,const int  &endSign)
{
	if(ch[i] == endSign)
	{
		r = NULL;
	}
	else
	{
		r = new TreeNode(ch[i]);
		_createPreOrder(r->left,ch,++i,endSign);
		_createPreOrder(r->right,ch,++i,endSign);
	}
}
 
class Solution {
public:
    vector<int> largestValues(TreeNode* root)
	{
        int hight = 0;
		vector<int> result;
		findNext(1,root,hight,result);
		return result;
    }
private:
	void findNext(int d,TreeNode* node,int& dp,vector<int> & vec)
	{
		if(node == NULL) return;
		else
		{
			if(d > dp)//如果是第一次到新的高度 就push新的数据 
			{
				dp = d;
				vec.push_back(node->val);
				cout<<d-1<<' '<<node->val<<endl;
			}
			else//否则与上一次push的进行比较 
			{
				if(node->val > vec[d - 1])
				{
					vec[d - 1] = node->val;
					cout<<d - 1<<' '<<node->val<<endl;
				}
				  
			}
			findNext(d + 1,node->left,dp,vec);
			findNext(d + 1,node->right,dp,vec); 
		}
	}
};

int main()//构造二叉树的方法有点问题 
{
	TreeNode* root1;
	int num[13] = {1,2,4,0,0,3,5,7,0,0,6,0,0};
	int i = 0;
	int end = 0;
	_createPreOrder(root1,num,i,end);
	Solution a;
	vector<int> b = a.largestValues(root1);
	
	for(int i = 0;i < b.size();i++)
	{
		cout<<b[i]<<endl;
	}
	
	return 0;
} 
