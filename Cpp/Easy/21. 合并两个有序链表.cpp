将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(l1&&l2){
            int val1 = l1->val;
            int val2 = l2->val;
            if(val1<val2){
                p->next = l1;
                p = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        if(l1){
            p->next = l1;
        }else if(l2){
            p->next = l2;
        }
        return dummy.next;
    }
};
