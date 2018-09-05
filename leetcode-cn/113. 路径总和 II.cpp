/*
 * 113. 路径总和 II.cpp
 *
 *  Created on: 2018年9月5日
 *      Author: garvin
 */

/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
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
    void getresults(vector<vector<int> >& results, vector<int>& result, TreeNode* root, int sum){
        if(root == NULL)
            return;
        if(sum == root->val && root->left == NULL && root->right == NULL){
            result.push_back(root->val);
            results.push_back(result);
            result.pop_back();
        }
        result.push_back(root->val);
        getresults(results, result, root->left, sum-root->val);
        getresults(results, result, root->right, sum-root->val);
        result.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > results;
        vector<int> result;
        if(root == NULL)
            return results;
        getresults(results, result, root, sum);
        return results;
    }
};
