/*
 * 99. 恢复二叉搜索树.cpp
 *
 *  Created on: 2018年9月5日
 *      Author: garvin
 */

/*
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
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
    void getrecord(TreeNode* root, TreeNode*& record1, TreeNode*& record2, TreeNode*& pre){
        if(root->left)
            getrecord(root->left, record1, record2, pre);
        if(root->val < pre->val && record1 == NULL)
            record1 = pre, record2 = root;
        if(record1 != NULL && root->val < pre->val)
            record2 = root;
        pre = root;
        if(root->right)
            getrecord(root->right, record1, record2, pre);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *record1 = NULL, *record2 = NULL;
        TreeNode *pre = new TreeNode(INT_MIN);
        getrecord(root, record1, record2, pre);
        swap(record1->val, record2->val);
    }
};

