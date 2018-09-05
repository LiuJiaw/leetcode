/*
 * 101. 对称二叉树.cpp
 *
 *  Created on: 2018年9月5日
 *      Author: garvin
 */

/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode *node1, TreeNode *node2){
        if(node1 == NULL && node2 == NULL)
            return true;
        if(node1 == NULL || node2 == NULL)
            return false;
        if(node1->val == node2->val)
            return check(node1->left, node2->right) && check(node1->right, node2->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return check(root->left, root->right);
    }
};

