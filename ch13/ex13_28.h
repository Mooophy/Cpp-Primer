//
//  ex13_28.h
//  Exercise 13.28
//
//  Created by pezy on 1/20/15.
//
//  Given the following classes, implement a default constructor and the necessary copy-control members.

#ifndef CP5_ex13_28_h
#define CP5_ex13_28_h

#include <string>
using std::string;

class TreeNode {
public:
    TreeNode() : value(string()), count(new int(1)), left(nullptr), right(nullptr) { }
    TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
    TreeNode& operator=(const TreeNode &rhs);
    ~TreeNode() {
        if (--*count == 0) {
            delete left;
            delete right;
            delete count;
        }
    }

private:
    std::string value;
    int         *count;
    TreeNode    *left;
    TreeNode    *right;
};

class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) { }
    BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) { }
    BinStrTree& operator=(const BinStrTree &bst);
    ~BinStrTree() { delete root; }

private:
    TreeNode *root;
};

#endif
