/*
 * 92. 反转链表 II.cpp
 *
 *  Created on: 2018年9月4日
 *      Author: garvin
 */

/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || m <= 0)
            return NULL;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *start = newhead;
        int p = n-m+1;
        while(--m){
            start = start->next;
        }
        ListNode *tmp1 = start->next;
        ListNode *tmp3 = start->next;
        start->next = NULL;
        while(p--){
            ListNode *tmp2 = tmp1->next;
            tmp1->next = start->next;
            start->next = tmp1;
            tmp1 = tmp2;
        }
        tmp3->next = tmp1;
        return newhead->next;
    }
};
