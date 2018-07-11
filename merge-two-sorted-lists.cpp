/*
 * merge-two-sorted-lists.cpp
 *
 *  Created on: 2018年7月11日
 *      Author: garvin
 */

/*Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists. */

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        ListNode* newhead = new ListNode(0);
        ListNode* tmp = newhead;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                tmp->next = l1;
                l1 = l1->next;
                tmp = tmp->next;
            }
            else{
                tmp->next = l2;
                l2 = l2->next;
                tmp = tmp->next;
            }
        }
        if(l1!=NULL){
            tmp->next = l1;
        }
        else if(l2 != NULL){
            tmp->next = l2;
        }
        return newhead->next;
    }
};
