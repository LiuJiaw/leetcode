/*
 * validate-binary-search-tree.cpp
 *
 *  Created on: 2018年7月16日
 *      Author: garvin
 */

/* Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees. */

/*
 * 这道题一开始没有考虑周全，只判定节点与其子节点的值的比较
 * 忽略了父节点之上的节点对于值范围的限定
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
    bool check(TreeNode *root, int xiaxian, int shangxian){
        if(root == NULL)
            return true;
        if(xiaxian>shangxian)
            return false;
        if(root->val >= xiaxian && root->val <= shangxian)
            return check(root->left, xiaxian, root->val-1)&&check(root->right, root->val+1, shangxian);
        return false;
    }
    bool isValidBST(TreeNode *root) {
        if(root == NULL)
            return true;
        return check(root->left, INT_MIN, root->val-1) && check(root->right, root->val+1, INT_MAX);
    }
};
