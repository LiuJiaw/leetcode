/*
 * recover-binary-search-tree.cpp
 *
 *  Created on: 2018年7月16日
 *      Author: garvin
 */


/*Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n ) space is pretty straight forward. Could you devise a constant space solution? */

/*
 * 首先中序遍历，存储至vector
 * 找出不符合顺序的两个数字
 * 注意有两种情况，两个数字相邻和不相邻
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
    void recoverTree(TreeNode *root) {
        if(root == NULL)
            return;
        stack<TreeNode*> s;
        vector<TreeNode*> record;
        s.push(root);
        while(!s.empty()){
            TreeNode* tmp = s.top();
            while(tmp->left){
                s.push(tmp->left);
                tmp = tmp->left;
            }
            while(!s.empty()){
                tmp = s.top();
                record.push_back(tmp);
                s.pop();
                if(tmp->right){
                    s.push(tmp->right);
                    break;
                }
            }
        }
        int recordsize = record.size();
        int i=0, j=0;
        for(i = 0; i<recordsize-1 && record[i]->val<record[i+1]->val; i++);
        for(j = i+1; j<recordsize-1 && record[j]->val<record[j+1]->val; j++);
        if(j == recordsize-1)
            j = i+1;
        else
            j = j+1;
        int v = record[i]->val;
        record[i]->val = record[j]->val;
        record[j]->val = v;
    }
};
