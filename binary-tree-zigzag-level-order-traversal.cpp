/*
 * binary-tree-zigzag-level-order-traversal.cpp
 *
 *  Created on: 2018年7月5日
 *      Author: garvin
 */


/*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree{3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]*/

/*
 * 之字形层次遍历，思路同几天前的普通层次遍历
 * 只是多了一个判断层数奇偶的变量
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        vector<int> aans;
        q.push(root);
        TreeNode *start = q.front();
        TreeNode *end = q.back();
        int hang = 0;
        while(!q.empty()){
            aans.push_back(start->val);
            if(start->left)
                q.push(start->left);
            if(start->right)
                q.push(start->right);

            if(start == end){
                end = q.back();
                hang++;
                if(hang%2 == 0)
                    reverse(aans.begin(), aans.end());
                ans.push_back(aans);
                aans.clear();
            }
            q.pop();
            start = q.front();
        }
        return ans;
    }
};


