/*
 * 106. 从中序与后序遍历序列构造二叉树.cpp
 *
 *  Created on: 2018年9月5日
 *      Author: garvin
 */

/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return NULL;
        int rootval = postorder[postorder.size()-1];
        TreeNode *root = new TreeNode(rootval);
        int index = 0;
        if(inorder.size() == 1)
            return root;
        for(; inorder[index]!=rootval && index<inorder.size(); index++);
        vector<int> tmp1(postorder.begin(), postorder.begin()+index);
        vector<int> tmp2(postorder.begin()+index, postorder.end()-1);
        vector<int> tmp3(inorder.begin(), inorder.begin()+index);
        vector<int> tmp4(inorder.begin()+1+index, inorder.end());
        root->left = buildTree(tmp3, tmp1);
        root->right = buildTree(tmp4, tmp2);
        return root;
    }
};

