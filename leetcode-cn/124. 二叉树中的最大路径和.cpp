/*
 * 124. 二叉树中的最大路径和.cpp
 *
 *  Created on: 2018年9月10日
 *      Author: garvin
 */

/*
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42
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
    int getmax(TreeNode* root, int& result){
        if(root == NULL)
            return 0;
        int maxleft = max(getmax(root->left, result), 0);
        int maxright = max(getmax(root->right, result), 0);
        result = max(result, root->val+maxleft+maxright);
        return max(maxleft, maxright)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int result = INT_MIN;
        getmax(root, result);
        return result;
    }
};



