/*
 * rotate-list .cpp
 *
 *  Created on: 2018年7月7日
 *      Author: garvin
 */

/*Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given1->2->3->4->5->NULLand k =2,
return4->5->1->2->3->NULL. */

/*
 * k为长度的整数倍，则直接返回
 * 求出右移k单位后的头结点
 * 对链表重新拼接
 * 排行评论区比较好的解法是求出链表长度后，
 * 首尾相接成环，然后断开
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL || head->next==NULL)
            return head;

        int length = 0;
        ListNode *tmp = head;
        ListNode *end = tmp;
        while(tmp != NULL){
            end = tmp;
            tmp = tmp->next;
            length++;
        }
        k %= length;
        if(k==0)
            return head;

        int times = length-k;
        ListNode *ans = head;
        while(times--){
            tmp = ans;
            ans = ans->next;
        }
        tmp->next = NULL;
        end->next = head;
        return ans;
    }
};

