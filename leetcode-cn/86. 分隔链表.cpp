/*
 * 86. 分隔链表.cpp
 *
 *  Created on: 2018年8月31日
 *      Author: garvin
 */

/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* headl=new ListNode(0), *headh=new ListNode(0);
        ListNode* tmpl=headl, *tmph=headh;
        ListNode* tmp=head;
        while(tmp != NULL){
            if(tmp->val >= x){
                tmph->next = tmp;
                tmp = tmp->next;
                tmph = tmph->next;
                tmph->next = NULL;
            }
            else{
                tmpl->next = tmp;
                tmp = tmp->next;
                tmpl = tmpl->next;
                tmpl->next = NULL;
            }
        }
        tmpl->next = headh->next;
        return headl->next;
    }
};


