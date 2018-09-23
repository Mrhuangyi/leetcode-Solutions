给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1 || !head) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        ListNode* prev = &dummy;
        while(p) {
            prev = p;
            for(int i = 0; i < k; i++) {
                p = p->next;
                if(!p) {
                    return dummy.next;
                }
            }
            p = reverse(prev, p->next);
        }
        return dummy.next;
    }
    ListNode* reverse(ListNode* prev, ListNode* end) {
        ListNode* p = prev->next;
        while(p->next != end) {
            ListNode* n = p->next;
            p->next = n->next;
            n->next = prev->next;
            prev->next = n;
        }
        return p;
    }
};
