/*
 * 82. 删除排序链表中的重复元素 II.cpp
 *
 *  Created on: 2018年8月28日
 *      Author: garvin
 */



/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5

示例 2:

输入: 1->1->1->2->3
输出: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *slow = newhead, *fast = head;
        bool isexicted = false;
        while(fast != NULL){
            if(fast->next !=NULL){
                if(fast->val == fast->next->val){
                    isexicted = true;
                }
                else{
                    if(isexicted == false){
                        slow->next = fast;
                        slow = slow->next;
                    }
                    isexicted = false;
                }
            }
            else{
                if(isexicted)
                    slow->next =NULL;
                else
                    slow->next = fast;
            }
            fast = fast->next;
        }
        return newhead->next;
    }
};


