反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        for(int i = 1; i < m; i++) {
            p = p->next;
        }
        ListNode* pm = p->next;
        for(int i = m; i < n; i++) {
            ListNode* n = pm->next;
            pm->next = n->next;
            n->next = p->next;
            p->next = n;
        }
        return dummy.next;
    }
};
