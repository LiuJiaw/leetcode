/*
 * construct-binary-tree-from-inorder-and-postorder-traversal.cpp
 *
 *  Created on: 2018年7月23日
 *      Author: garvin
 */

/* Given inorder and postorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree. */

/*
 * 根据中序及后序遍历的序列构建树
 * 观察可知，后序遍历最后一位为根节点
 * 中序遍历，根节点将左右子树划分为两部分
 * 根据两部分的长度，可得两部分的后序遍历
 * 递归即可
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
    TreeNode* getroot(vector<int>& inorder, vector<int>& postorder){
        if(inorder.size()==0)
            return NULL;
        vector<int>::iterator it;
        it = find(inorder.begin(), inorder.end() ,postorder.back());
        TreeNode* root = new TreeNode(*it);
        vector<int> frontinorder(inorder.begin(), it);
        vector<int> backinorder(it+1, inorder.end());
        vector<int> frontpostorder(postorder.begin(), postorder.begin()+frontinorder.size());
        vector<int> backpostorder(postorder.begin()+frontpostorder.size(), postorder.end()-1);
        root->left = getroot(frontinorder, frontpostorder);
        root->right = getroot(backinorder, backpostorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size()!=postorder.size() || inorder.size()<=0)
            return NULL;
        TreeNode* root = getroot(inorder, postorder);
        return root;
    }
};
