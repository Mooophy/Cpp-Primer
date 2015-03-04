//
//  ex13_28.cpp
//  Exercise 13.28
//
//  Created by pezy on 1/20/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Given the following classes, implement a default constructor and the necessary copy-control members.

#include "ex13_28.h"

TreeNode& TreeNode::operator=(const TreeNode &rhs)
{
    ++*rhs.count;
    if (--*count == 0) {
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }

        delete count;
        count = nullptr;
    }
    value = rhs.value;
    left = rhs.left;
    right = rhs.right;
    count = rhs.count;
    return *this;
}

BinStrTree& BinStrTree::operator=(const BinStrTree &bst)
{
    TreeNode *new_root = new TreeNode(*bst.root);
    delete root;
    root = new_root;
    return *this;
}
