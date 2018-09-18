/*
 * 145. 二叉树的后序遍历.cpp
 *
 *  Created on: 2018年9月18日
 *      Author: garvin
 */

/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> q;
        vector<int> result;
        while(!q.empty() || root){
            while(root){
                q.push(root);
                result.push_back(root->val);
                root = root->right;
            }
            root = q.top();
            q.pop();
            root = root->left;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
