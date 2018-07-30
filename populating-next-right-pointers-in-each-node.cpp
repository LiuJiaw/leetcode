/*
 * populating-next-right-pointers-in-each-node.cpp
 *
 *  Created on: 2018年7月23日
 *      Author: garvin
 */

 /*Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set toNULL.
Initially, all next pointers are set toNULL.
Note:
    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL*/


/*
 * 递归，不过貌似违反了题目中使用常数空间的要求？
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void conn(TreeLinkNode* leftnode, TreeLinkNode* rightnode){
        if(leftnode == NULL)
            return;
        leftnode->next = rightnode;
        conn(leftnode->left, leftnode->right);
        conn(leftnode->right, rightnode->left);
        conn(rightnode->left, rightnode->right);
        return;
    }
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        conn(root->left, root->right);
    }
};


/*Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
   You may only use constant extra space.

For example,
Given the following binary tree,

        1
      /  \
     2    3
    / \    \
   4   5    7
After calling your function, the tree should look like:
        1 -> NULL
      /  \
     2 -> 3 -> NULL
    / \    \
   4-> 5 -> 7 -> NULL*/


/*
 * 一个指针用于指向每一层第一个节点
 * 另一个指针遍历该层
 * func函数用于更新lastnode和nextnode的值以及更新lastnode的指向
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void func(TreeLinkNode*& lastone, TreeLinkNode*& nextone, TreeLinkNode* node){
        if(lastone == NULL)
            lastone = node;
        else if(nextone == NULL){
            nextone = node;
            lastone->next = nextone;
        }
        else{
            lastone = nextone;
            nextone = node;
            lastone->next = nextone;
        }
    }
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        TreeLinkNode* tmp = root;
        TreeLinkNode* lastone = NULL;
        TreeLinkNode* nextone = NULL;
        bool firsttime =false;
        while(root){
            tmp = root;
            firsttime = true;
            lastone = nextone = NULL;
            while(tmp){
                if(tmp->left != NULL){
                    func(lastone, nextone, tmp->left);
                    root = firsttime ? tmp->left : root;
                    firsttime = false;
                }
                if(tmp->right != NULL){
                    func(lastone, nextone, tmp->right);
                    root = firsttime ? tmp->right : root;
                    firsttime = false;
                }
                tmp = tmp->next;
            }
            if(firsttime)
                break;
        }
    }
};


