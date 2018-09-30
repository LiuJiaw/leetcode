/*
 * 203.删除链表中的节点.cpp
 *
 *  Created on: 2018年9月30日
 *      Author: garvin
 */

/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *tmp = newhead;
        while(tmp->next){
            if(tmp->next->val == val)
                tmp->next = tmp->next->next;
            else
                tmp = tmp->next;
        }
        return newhead->next;
    }
};


