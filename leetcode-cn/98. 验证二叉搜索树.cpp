/*
 * 98. 验证二叉搜索树.cpp
 *
 *  Created on: 2018年9月4日
 *      Author: garvin
 */

/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
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
    bool isBST(TreeNode *root, long long int min, long long int max){
        if(root == NULL)
            return true;
        if(root->val<=min || root->val>=max)
            return false;
        return isBST(root->left, min, root->val)&&isBST(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        long long int Min = -2147483649;
        long long int Max = 2147483648;
        return isBST(root->left, Min, root->val)&&isBST(root->right, root->val, Max);
    }
};

