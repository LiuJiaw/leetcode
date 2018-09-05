/*
 * 103. 二叉树的锯齿形层次遍历.cpp
 *
 *  Created on: 2018年9月5日
 *      Author: garvin
 */

/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > results;
        vector<int> result;
        if(root == NULL)
            return results;
        TreeNode *start = NULL, *end = NULL;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            start = q.front(), end = q.back();
            result.clear();
            while(size--){
                if(start->left)
                    q.push(start->left);
                if(start->right)
                    q.push(start->right);
                result.push_back(start->val);
                q.pop();
                start = q.front();
            }
            if(level%2 == 0)
                reverse(result.begin(), result.end());
            results.push_back(result);
            level++;
        }
        return results;
    }
};

