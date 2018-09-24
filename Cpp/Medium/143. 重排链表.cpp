给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.


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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode dummy(0);
        while(fast) {
            ListNode* n = dummy.next;
            dummy.next = fast;
            ListNode* m = fast->next;
            fast->next = n;
            fast = m;
        }
        slow = head;
        fast = dummy.next;
        while(slow) {
            if(fast != NULL) {
                ListNode* n = slow->next;
                slow->next = fast;
                ListNode* m = fast->next;
                fast->next = n;
                fast = m;
                slow = n;
            } else {
                break;
            }
        }
    }
};
