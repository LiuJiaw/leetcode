/*
 * 138. 复制带随机指针的链表.cpp
 *
 *  Created on: 2018年9月15日
 *      Author: garvin
 */

/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深度拷贝。
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> mp;
        RandomListNode *tmp = head;
        while(tmp){
            RandomListNode* newtmp = new RandomListNode(tmp->label);
            mp[tmp] = newtmp;
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp){
            mp[tmp]->random = mp[tmp->random];
            mp[tmp]->next = mp[tmp->next];
            tmp = tmp->next;
        }
        return mp[head];
    }
};

