/*
 * 24. 两两交换链表中的节点.cpp
 *
 *  Created on: 2018年8月26日
 *      Author: garvin
 */


/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

说明:

    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* tmp = newhead;
        ListNode* record = newhead;
        while(tmp->next!=NULL && tmp->next->next!=NULL){
            record = tmp->next->next;
            tmp->next->next = record->next;
            record->next = tmp->next;
            tmp->next = record;
            tmp = record->next;
        }
        tmp = newhead->next;
        delete newhead;
        return tmp;
    }
};
