/*
 * 160. 相交链表.cpp
 *
 *  Created on: 2018年9月23日
 *      Author: garvin
 */

/*
编写一个程序，找到两个单链表相交的起始节点。

例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

在节点 c1 开始相交。



注意：

    如果两个链表没有交点，返回 null.
    在返回结果后，两个链表仍须保持原有的结构。
    可假定整个链表结构中没有循环。
    程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt = 0;
        ListNode * tmp =  headA;
        while(tmp)
        {
            cnt++;
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp)
        {
            cnt--;
            tmp = tmp->next;
        }

        ListNode* another = NULL;
        tmp = cnt>0 ?headA:headB;
        another = tmp==headA?headB:headA;
        cnt = cnt>0?cnt:-1*cnt;
        while(cnt)
        {
            tmp=tmp->next;
            cnt--;
        }

        while(tmp && another)
        {
            if(tmp == another)
            {
                return tmp;
            }
            tmp=tmp->next;
            another= another->next;
        }
        return NULL;
    }
};

