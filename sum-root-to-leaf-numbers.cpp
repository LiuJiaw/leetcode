/*
 * sum-root-to-leaf-numbers.cpp
 *
 *  Created on: 2018年7月4日
 *      Author: garvin
 */

/* Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path1->2->3which represents the number123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3


The root-to-leaf path1->2represents the number12.
The root-to-leaf path1->3represents the number13.

Return the sum = 12 + 13 =25. */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*
 * 这道题我的基本思路是，若节点是叶子节点，则将路径值放入到vector中，
 * 若不是叶子节点，则查看是否有左子树右子树，有的话向左子树或右子树前进。
 * 需要注意的是，当返回上一层时要将num值复原，
 * 之前只注重了叶子节点返回时的复原，导致WA
 * */

class Solution {
public:
    void sumnum(TreeNode *root, int& num, vector<int>& ans){
        num *= 10;
        num += root->val;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(num);
            num /= 10;
            return;
        }
        if(root->left!=NULL)
            sumnum(root->left, num, ans);
        if(root->right!=NULL)
            sumnum(root->right, num, ans);
        num /= 10;
    }
    int sumNumbers(TreeNode *root) {
        if(root == NULL)
            return 0;
        vector<int> ans;
        int num = root->val;
        int Ans = 0;

        if(root->left==NULL && root->right==NULL)
            ans.push_back(num);

        if(root->left!=NULL)
            sumnum(root->left, num, ans);
        if(root->right!=NULL)
            sumnum(root->right, num, ans);

        vector<int>::iterator item;
        for(item = ans.begin(); item!=ans.end(); item++){
            Ans += (*item);
        }
        return Ans;
    }
};


