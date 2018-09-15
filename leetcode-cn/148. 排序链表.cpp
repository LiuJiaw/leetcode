/*
 * 148. 排序链表.cpp
 *
 *  Created on: 2018年9月15日
 *      Author: garvin
 */

/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4

示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5
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
    ListNode* Sort(ListNode* head, ListNode* tail){
        if(head == tail)
            return head;
        ListNode* fast = head, *slow = head;
        while(fast!=tail && fast->next!=tail){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *newhead1 = Sort(head, slow);
        ListNode *newhead2 = Sort(fast, tail);
        ListNode *newhead = new ListNode(0);
        ListNode *newtmp = newhead;
        while(newhead1 && newhead2){
            if(newhead1->val < newhead2->val)
                newtmp->next = newhead1, newtmp = newtmp->next, newhead1 = newhead1->next, newtmp->next = NULL;
            else
                newtmp->next = newhead2, newtmp = newtmp->next, newhead2 = newhead2->next, newtmp->next = NULL;
        }
        if(newhead1)
            newtmp->next = newhead1;
        if(newhead2)
            newtmp->next = newhead2;
        return newhead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* tail = head;
        while(tail->next)
            tail = tail->next;
        head = Sort(head, tail);
        return head;
    }
};


