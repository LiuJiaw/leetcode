/*
 * 105. 从前序与中序遍历序列构造二叉树.cpp
 *
 *  Created on: 2018年9月5日
 *      Author: garvin
 */

/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return NULL;
        int rootval = preorder[0];
        TreeNode *root = new TreeNode(rootval);
        int index = 0;
        if(preorder.size() == 1)
            return root;
        for(; inorder[index]!=rootval && index<preorder.size(); index++);
        vector<int> tmp1(preorder.begin()+1, preorder.begin()+1+index);
        vector<int> tmp2(preorder.begin()+1+index, preorder.end());
        vector<int> tmp3(inorder.begin(), inorder.begin()+index);
        vector<int> tmp4(inorder.begin()+1+index, inorder.end());
        root->left = buildTree(tmp1, tmp3);
        root->right = buildTree(tmp2, tmp4);
        return root;
    }
};

