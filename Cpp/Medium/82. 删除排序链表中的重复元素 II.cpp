给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* p = head;
        while(p && p->next) {
            if(p->val != p->next->val) {
                prev = p;
                p = p->next;
            } else {
                int val = p->val;
                ListNode* n = p->next->next;
                while(n) {
                    if(n->val != val) {
                        break;
                    }
                    n = n->next;
                }
                prev->next = n;
                p = n;
            }
        }
        return dummy.next;
    }
};
