/*
 * convert-sorted-list-to-binary-search-tree.cpp
 *
 *  Created on: 2018年7月23日
 *      Author: garvin
 */

/*Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST. */

/*
 * 使用快慢指针
 * 慢指针为子部分的根节点
 * 需要注意的是，对于快指针到达尾部的情况
 * 若其下一个并非NULL，则慢指针需要往后移以下
 * 例如 1 3 链表，根节点为3而非1
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
    TreeNode *getroot(ListNode* head, ListNode* rear){
        if(head == rear)
            return NULL;
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast->next!=rear && fast->next->next!=rear){
            fast = fast->next->next, slow = slow->next;
        }
        if(fast->next != rear) slow = slow->next;
        TreeNode *root = new TreeNode(slow->val);
        root->left = getroot(head, slow);
        root->right = getroot(slow->next, rear);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode* rear = NULL;
        TreeNode* root = getroot(head, rear);
        return root;
    }
};
