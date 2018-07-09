/*
 * add-two-numbers.cpp
 *
 *  Created on: 2018年7月9日
 *      Author: garvin
 */


/* You are given two linked lists representing two non-negative numbers.
 The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8 */

/*
 * 需要判断进位
 * 尤其是要注意最后一个节点
 * 在两条链表都为空的情况下
 * 需要判断是否残存一个进位
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2 ==NULL)
            return NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;
        bool jinwei = false;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val+l2->val+jinwei;
            sum >= 10 ? jinwei=true, sum-=10 : jinwei=false, sum = sum;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val+jinwei;
            sum >= 10 ? jinwei=true, sum-=10 : jinwei=false, sum = sum;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            int sum = l2->val+jinwei;
            sum >= 10 ? jinwei=true, sum-=10 : jinwei=false, sum = sum;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
            l2 = l2->next;
        }
        if(jinwei)
            tmp->next = new ListNode(1);

        return head->next;

    }
};
