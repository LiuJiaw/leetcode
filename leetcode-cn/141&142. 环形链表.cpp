/*
 * 141&142. 环形链表.cpp
 *
 *  Created on: 2018年9月15日
 *      Author: garvin
 */

/*
给定一个链表，判断链表中是否有环。

进阶：
你能否不使用额外空间解决此题？
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head, *slow = head;
        while(true){
            fast = fast->next;
            if(fast == NULL)
                break;
            fast = fast->next;
            if(fast == NULL)
                break;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        if(fast == NULL)
            return false;
        return true;
    }
};

/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

说明：不允许修改给定的链表。

进阶：
你是否可以不用额外空间解决此题？
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode *fast = head, *slow = head;
        int step = 0;
        while(true){
            if(fast->next == NULL || fast->next->next == NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
            step++;
            if(fast == slow)
                break;
        }
        fast = head;
        for(int i=0; i<step; i++)
            fast = fast->next;
        slow = head;
        while(slow != fast)
            slow = slow->next, fast = fast->next;
        return slow;
    }
};
