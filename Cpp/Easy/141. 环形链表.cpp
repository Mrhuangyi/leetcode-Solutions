给定一个链表，判断链表中是否有环。

进阶：
你能否不使用额外空间解决此题？

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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
