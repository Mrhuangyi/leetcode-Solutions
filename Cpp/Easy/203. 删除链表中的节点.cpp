删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode *p = head,*tmp = head,*dum = new ListNode(-1);
        dum->next = head;
        p = dum;
        while(p->next!=NULL){
            if(p->next->val==val){
                tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            }else{
                p = p->next;
            }
        }
        head = dum->next;
        delete dum;
        return head;
    }
};
