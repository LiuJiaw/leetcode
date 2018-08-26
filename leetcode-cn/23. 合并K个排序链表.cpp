/*
 * 23. 合并K个排序链表.cpp
 *
 *  Created on: 2018年8月26日
 *      Author: garvin
 */

/*
 * 用的归并排序
 */

/*合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6*/


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
    void getlist(vector<ListNode*>& lists, int start, int end){
        int middle = (start+end)/2;
        if(end==start)
            return;
        if(end-start>1){
            getlist(lists, start, middle);
            getlist(lists, middle+1, end);
        }
        if(lists[middle+1] == NULL)
        	return;
        if(lists[start] == NULL){
            swap(lists[start], lists[middle+1]);
            return;
        }
        if(lists[start]->val > lists[middle+1]->val)
            swap(lists[start], lists[middle+1]);
        ListNode *start1, *start2, *record1, *record2;
        start1 = lists[start], start2 = lists[middle+1], record1 = start1, record2 = start2;
        while(start1!=NULL && start2!=NULL){
            if(start1->val <= start2->val)
                record1 = start1, start1 = start1->next;
            else if(start1->val > start2->val){
                record2 = start2->next;
                start2->next = start1;
                record1->next = start2;
                record1 = record1->next;
                start2 = record2;
            }
        }
        if(start2!=NULL)
            record1->next = start2;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0)   return NULL;
        if(size == 1)   return lists[0];
        getlist(lists, 0, size-1);
        return lists[0];
    }
};

