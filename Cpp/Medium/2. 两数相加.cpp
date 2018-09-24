给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        int cn = 0;
        while(l1 || l2) {
            int val = cn + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            cn = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }
        if(cn != 0) {
            p->next = new ListNode(cn);
            p = p->next;
        }
        return dummy.next;
    }
};
