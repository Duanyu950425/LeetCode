#include<iostream>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :data(x) {}
};
class Solution 
{
public:
	int run(TreeNode *root) 
	{
		if (root == NULL)
			return 0;
		if (root->left == NULL)
			return run(root->right) + 1;
		if (root->right == NULL)
			return run(root->left) + 1;
		int leftDepth = run(root->left) + 1;
		int rightDepth = run(root->right) + 1;
		return (leftDepth < rightDepth) ? leftDepth : rightDepth;
	}
	TreeNode * root;
};

int main01()
{
	TreeNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6);
	Solution s;
	s.root = &node1;
	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	cout << s.run(s.root) << endl;
	return 0;
}