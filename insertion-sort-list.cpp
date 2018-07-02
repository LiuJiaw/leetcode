/*
 * insertion-sort-list.cpp
 *
 *  Created on: 2018年7月2日
 *      Author: garvin
 */

//Sort a linked list using insertion sort.

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
    void insert(ListNode *head, ListNode *toinsert){
        while(head->next != NULL){
            if(head->next->val > toinsert->val){
                toinsert->next = head->next;
                head->next = toinsert;
                return;
            }
            head = head->next;
        }
        head->next = toinsert;
        toinsert->next = NULL;
    }

    ListNode *insertionSortList(ListNode *head) {
        ListNode *ans = new ListNode(0);
        while(head!=NULL){
            ListNode *tmp = head->next;
            insert(ans, head);
            head = tmp;
        }
        return ans->next;
    }
};
