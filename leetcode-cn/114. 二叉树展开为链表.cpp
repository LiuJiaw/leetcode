/*
 * 114. 二叉树展开为链表.cpp
 *
 *  Created on: 2018年9月10日
 *      Author: garvin
 */

/*
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        queue<TreeNode*> q;
        if(root == NULL)
            return;
        while(!s.empty() || root!=NULL){
            while(root){
                q.push(root);
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
        TreeNode* newroot = new TreeNode(0);
        TreeNode* tmp = newroot;
        while(!q.empty()){
            TreeNode* tmp1 = q.front();
            q.pop();
            tmp->right = tmp1;
            tmp->left = NULL;
            tmp = tmp1;
        }
        tmp->left = NULL;
        tmp->right = NULL;
        return;
    }
};

