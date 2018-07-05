/*
 * binary-tree-maximum-path-sum.cpp
 *
 *  Created on: 2018年7月5日
 *      Author: garvin
 */

/*Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
For example:
Given the below binary tree,

       1
      / \
     2   3
Return6. */

/*
 * 求树中某点到某点的最大值路径，仍然采用递归的思想
 * 假设某条路径中，离根节点最近的节点为k，
 * 那么路径的长度就是k节点的值加上起点到k的左节点的路径值加上k的右节点到终点的路径值
 * 为了避免重复计算，我们通过递归先来到达较低的节点，
 * 每一次递归后，都将此时的根节点作为k，计算最大的路径长度，并与Max相比较决定是否更新
 * 每一次递归返回的是当前子树中，到达根节点的最大路径值，以供当前子树根节点的父节点作参考
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
    int maxsum(TreeNode *root, int& Max){
        if(root == NULL)
            return 0;
        int maxleft = maxsum(root->left, Max);
        int maxright = maxsum(root->right, Max);
        int ans = root->val;
        if(maxleft > 0)
            ans+=maxleft;
        if(maxright > 0)
            ans+=maxright;
        Max = max(Max, ans);
        if(max(maxleft, maxright) > 0)
            return root->val + max(maxleft, maxright);
        return root->val;
    }
    int maxPathSum(TreeNode *root) {
        if(root == NULL)
            return 0;
        int Max = INT_MIN;
        int maxleft = maxsum(root->left, Max);
        int maxright = maxsum(root->right, Max);
        int ans = root->val;
        if(maxleft > 0)
            ans+=maxleft;
        if(maxright > 0)
            ans+=maxright;
        Max = max(Max, ans);
        return Max;
    }
};


