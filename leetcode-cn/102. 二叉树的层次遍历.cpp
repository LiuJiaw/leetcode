/*
 * 102. 二叉树的层次遍历.cpp
 *
 *  Created on: 2018年9月5日
 *      Author: garvin
 */

/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > results;
        vector<int> result;
        if(root == NULL)
            return results;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *front = q.front(), *rear = q.back();
            result.clear();
            while(front != rear){
                result.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                q.pop();
                front = q.front();
            }
            result.push_back(front->val);
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
            q.pop();
            front = q.front();
            results.push_back(result);
        }
        return results;
    }
};

