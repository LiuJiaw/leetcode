/*
 * 2. 两数相加.cpp
 *
 *  Created on: 2018年8月23日
 *      Author: garvin
 */

/*
 * 本来给的就是逆序的链表，所以按照相加运算的方法即可
 * 要注意的是，最后的最后，要判断是否有进位剩余
 */

/*给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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
    int check(int a, int& c){
        int ans=0;
        if(a+c>=10)
        {
            ans = a+c-10;
            c=1;
        }
        else{
            ans = a+c;
            c=0;
        }
        return ans;
    }
    int check(int a, int b, int& c){
        int ans=0;
        if(a+b+c>=10)
        {
            ans = a+b+c-10;
            c=1;
        }
        else{
            ans = a+b+c;
            c=0;
        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int jinwei=0;
        int num;
        ListNode* ans = new ListNode(check(l1->val, l2->val, jinwei));
        ListNode* tmp = ans;
        l1 = l1->next;
        l2 = l2->next;
        while(l1!=NULL && l2!=NULL){
            tmp->next = new ListNode(check(l1->val, l2->val, jinwei));
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            tmp->next = new ListNode(check(l1->val, jinwei));
            tmp = tmp->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            tmp->next = new ListNode(check(l2->val, jinwei));
            tmp = tmp->next;
            l2 = l2->next;
        }
        if(jinwei)
            tmp->next = new ListNode(1);

        return ans;
    }
};
