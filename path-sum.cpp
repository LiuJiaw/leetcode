/*
 * path-sum.cpp
 *
 *  Created on: 2018年7月7日
 *      Author: garvin
 */

/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree andsum = 22, */


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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return false;
        sum -= root->val;
        if(root->left==NULL && root->right==NULL && sum==0)
            return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

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
    void getPath(TreeNode *root, int sum, vector<int>& record, vector<vector<int>>& ans){
        if(root==NULL)
            return;
        sum -= root->val;
        record.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==0){
            ans.push_back(record);
            record.erase(record.end()-1);
            return;
        }
        getPath(root->left, sum, record, ans);
        getPath(root->right, sum, record, ans);
        record.erase(record.end()-1);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        sum -= root->val;
        vector<int> record;
        record.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==0)
            ans.push_back(record);
        getPath(root->left, sum, record, ans);
        getPath(root->right, sum, record, ans);
        return ans;
    }
};


