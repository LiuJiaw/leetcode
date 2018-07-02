/*
 * minimum-depth-of-binary-tree.cpp
 *
 *  Created on: 2018年7月2日
 *      Author: garvin
 */


//Given a binary tree,
//find its minimum depth.
//The minimum depth is the number of nodes
//along the shortest path from the root node down to the nearest leaf node.


//需要注意的是，此题并不能像求最长路径那样，递归返回左子树和右子树中最长的路径。
//这是因为某节点可能只有单支子树，并非为叶子节点

class Solution {
public:
    int run(TreeNode *root) {
        if(root == NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        if(root->left==NULL || root->right==NULL)
            return 1+max(run(root->left), run(root->right));
        return 1+min(run(root->left), run(root->right));
    }
};

