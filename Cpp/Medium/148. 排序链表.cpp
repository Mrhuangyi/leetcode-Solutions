在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5


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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(fast);
        return merge(p1, p2);
    }
    ListNode* merge(ListNode* L1, ListNode* L2) {
        if(!L1) {
            return L2;
        } else if(!L2) {
            return L1;
        } else if(!L1 && !L2) {
            return NULL;
        }
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(L1 && L2) {
            if(L1->val < L2->val) {
                p->next = L1;
                L1 = L1->next;
            } else {
                p->next = L2;
                L2 = L2->next;
            }
            p = p->next;
        }
        if(L1) {
            p->next = L1;
        } else if(L2) {
            p->next = L2;
        }
        return dummy.next;
    }
};
