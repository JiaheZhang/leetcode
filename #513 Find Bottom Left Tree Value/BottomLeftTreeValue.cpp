#include<iostream>
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
    int findBottomLeftValue(TreeNode* root)
	{
		int deep = 0;
		int value = 0;
		findNext(0,root,deep,value);
        return value;
    }
private:
	void findNext(int d,TreeNode* node,int& dp,int& va)
	{
		if(node == NULL) return;
		else
		{
			if(d > dp)
			{
				dp = d;
				va = node->val;
			}
			findNext(d + 1,node->left,dp,va);
			findNext(d + 1,node->right,dp,va); 
		}
	}
};

int main()
{
	TreeNode* root1;
	int num[13] = {1,2,4,0,0,3,5,7,0,0,6,0,0};
	int i = 0;
	int end = 0;
	_createPreOrder(root1,num,i,end);
	Solution a;
	cout<<a.findBottomLeftValue(root1);
	return 0;
} 
