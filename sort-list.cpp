/*
 * sort-list.cpp
 *
 *  Created on: 2018年7月2日
 *      Author: garvin
 */

//Sort a linked list in O(n log n) time using constant space complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//使用的是归并排序，分的时候使用快慢指针，合并为merge函数

class Solution {
public:
    ListNode *Merge(ListNode *start1, ListNode *start2){
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;
        while(start1!=NULL && start2!=NULL){
            if(start1->val <= start2->val){
                tmp->next = start1;
                start1 = start1->next;
            }
            else if(start1->val >start2->val){
                tmp->next = start2;
                start2 = start2->next;
            }
            tmp = tmp->next;
            tmp->next = NULL;
        }
        if(start1 != NULL)
            tmp->next = start1;
        if(start2 != NULL)
            tmp->next = start2;
        return head->next;
    }

    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        if(head->next->next == NULL){
            if(head->val>head->next->val){
                ListNode *last = head->next;
                last->next = head;
                head->next = NULL;
                head = last;
            }
            return head;
        }

        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;

        ListNode *start1 = sortList(head);
        ListNode *start2 = sortList(fast);

        head = Merge(start1, start2);

        return head;
    }
};
