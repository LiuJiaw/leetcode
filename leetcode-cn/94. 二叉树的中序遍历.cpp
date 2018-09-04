/*
 * 94. 二叉树的中序遍历.cpp
 *
 *  Created on: 2018年9月4日
 *      Author: garvin
 */

/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> s;
        while(!s.empty() || root!=NULL){
            while(root!=NULL){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};
