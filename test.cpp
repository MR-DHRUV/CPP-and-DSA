#include <bits/stdc++.h>

// Following is the Binary Tree node structure:

// class TreeNode
// {

// public:
// 	int data;
// 	TreeNode *left;
// 	TreeNode *right;

// 	TreeNode(int data)
// 	{
// 		this->data = data;
// 		left = NULL;
// 		right = NULL;
// 	}

// 	~TreeNode()
// 	{
// 		if (left)
// 		{
// 			delete left;
// 		}

// 		if (right)
// 		{
// 			delete right;
// 		}
// 	}
// };

void getInorder(TreeNode<int> *root, vector<int> &in)
{
	if (root == NULL)
	{
		return;
	}

	getInorder(root->left, in);
	in.push_back(root->data);
	getInorder(root->right, in);
}

TreeNode<int> *buildFromInorder(vector<int> in, int s, int e)
{
	if (s > e)
	{
		return;
	}

	int mid = s + (e - s) / 2;

	TreeNode<int> *t = new TreeNode<int>(in[mid]);
	t->left = buildFromInorder(in, s, mid - 1);
	t->left = buildFromInorder(in, mid + 1, e);

	return t;
}

vector<int> mergeArr(vector<int> in1, vector<int> in2)
{
	int i = 0;
	int j = 0;

	vector<int> ans;

	while (i < in1.size() && j < in2.size())
	{
		if (in1[i] == in2[j])
		{
			ans.push_back(in2[j]);
			i++;
			j++;
		}
		else if (in1[i] > in2[j])
		{
			ans.push_back(in2[j++]);
		}
		else
		{
			ans.push_back(in1[i++]);
		}
	}

	while (i < in1.size())
	{
		ans.push_back(in1[i++]);
	}

	while (j < in2.size())
	{
		ans.push_back(in2[j++]);
	}

	return ans;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
	// approach 1
	// find inorder of both
	// merge inorder in sorted way
	// build tree from inorder

	vector<int> in1;
	vector<int> in2;

	getInorder(root1, in1);
	getInorder(root2, in2);

	vector<int> in = mergeArr(in1, in2);

	TreeNode<int> *ans = buildFromInorder(in,0,in.size()-1);
	return ans;
}