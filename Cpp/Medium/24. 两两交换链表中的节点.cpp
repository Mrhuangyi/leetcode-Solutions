/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
说明:

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
        
        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;
        
        return secondNode;
    }
};

*/

//
//  swapNodes.cpp
//  LeetCode
//
//  Created by a on 2018/10/19.
//  Copyright © 2018 Leetcode. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

ListNode* creat( int Array[]) {
    ListNode *p, *pre, *head;
    head = new ListNode(0);
    head->next = NULL;
    pre = head;
    for(int i = 0; i < 5; i++) {
        p = new ListNode(0);
        p->val = Array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}
ListNode* swapPairs( ListNode* head ) {
    if(!head || !head->next) {
        return NULL;
    }
    ListNode* p = head;
    while(p && p->next) {
        swap(p->val, p->next->val);
        p = p->next->next;
    }
    return head;
}
ListNode* swapPairs2(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = head;
    ListNode* pre = dummy;
    ListNode* temp;
    while(current && current->next) {
        temp = current->next->next;
        current->next->next = current;
        pre->next = current->next;
        current->next = temp;
        pre = current;
        current = current->next;
    }
    return dummy->next;
}
int main()
{
    int Array[5] = {1, 2, 3, 4, 5};
    ListNode* head1 = creat(Array);
    ListNode* head2 = creat(Array);
    ListNode* L = swapPairs(head1);
    //L = L->next;
    ListNode* res = swapPairs2(head2);
    
    while(L != NULL) {
        printf("%d ", L->val);
        L = L->next;
    }
    printf("\n");
    while(res != NULL) {
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}
