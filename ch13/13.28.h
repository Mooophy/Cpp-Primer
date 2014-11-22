#ifndef __TREENODE_H__
#define __TREENODE_H__

#include <string>

class TreeNode
{
public:
	TreeNode() : count(0), left(0), right(0) { }
	TreeNode(const TreeNode &origin);
	TreeNode &operator=(const TreeNode &origin);

	~TreeNode();
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

inline TreeNode::TreeNode(const TreeNode &origin) : value(origin.value), count(origin.count)
{
	if (origin.left)
		left = new TreeNode(*origin.left);
	else
		left = 0;
	if (origin.right)
		right = new TreeNode(*origin.right);
	else
		right = 0;
}

inline TreeNode &TreeNode::operator = (const TreeNode &origin)
{
	value = origin.value;
	count = origin.count;

	TreeNode *temp_left, *temp_right;
	if (origin.left)
		temp_left = new TreeNode(*origin.left);
	else
		temp_left = 0;
	if (origin.right)
		temp_right = new TreeNode(*origin.right);
	else
		temp_left = 0;

	delete left;
	delete right;
	left = temp_left;
	right = temp_right;

	return *this;
}

inline TreeNode::~TreeNode()
{
	delete left;
	delete right;
}


class BinStrTree
{
public:
	BinStrTree() : root(0) { }
	BinStrTree(const BinStrTree &origin);
	BinStrTree &operator=(const BinStrTree &origin);

	~BinStrTree();
private:
	TreeNode *root;
};

inline BinStrTree::BinStrTree(const BinStrTree &origin)
{
	if (origin.root)
		root = new TreeNode(*origin.root);
	else
		root = 0;
}

inline BinStrTree &BinStrTree::operator=(const BinStrTree &origin)
{
	TreeNode *temp_root;
	if (origin.root)
		temp_root = new TreeNode(*origin.root);
	else
		temp_root = 0;
	delete root;
	root = temp_root;
	
	return *this;
}

inline BinStrTree::~BinStrTree()
{
	delete root;
}


#endif //__TREENODE_H__
