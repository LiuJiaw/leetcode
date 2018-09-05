/*
 * 109. 有序链表转换二叉搜索树.cpp
 *
 *  Created on: 2018年9月5日
 *      Author: garvin
 */

/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode *fast, *slow, *tmp;
        fast = head, slow = head, tmp = head;
        while(fast->next!=NULL && fast->next->next !=NULL){
            fast = fast->next->next;
            tmp = slow;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->right = sortedListToBST(slow->next);
        tmp->next = NULL;
        if(head != slow)
            root->left = sortedListToBST(head);
        else
            root->left = NULL;
        return root;
    }
};

