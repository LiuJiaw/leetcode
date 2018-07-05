/*
 * symmetric-tree.cpp
 *
 *  Created on: 2018年7月5日
 *      Author: garvin
 */

/* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
*/

/*
 * 镜像二叉树，使用递归比较容易理解
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool Check(TreeNode *node1, TreeNode *node2){
        if(node1 == NULL && node2 == NULL)
            return true;
        if(node1 == NULL || node2 == NULL)
            return false;
        if(node1->val != node2->val)
            return false;
        return Check(node1->left, node2->right) && Check(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;
        return Check(root->left, root->right);
    }
};


