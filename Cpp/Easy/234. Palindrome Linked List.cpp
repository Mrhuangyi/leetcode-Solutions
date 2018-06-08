Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return true;
        }
        ListNode* mid = findMid(head);
        mid->next = reverse(mid->next);
        mid = mid->next;
        while(head!=NULL&&mid!=NULL){
            if(head->val!=mid->val){
                return false;
            }
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
    ListNode* findMid(ListNode* now){
        ListNode* slow = now;
        ListNode* fast = now->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* now){
        ListNode* pre = NULL;
        while(now!=NULL){
            ListNode* temp = now->next;
            now->next = pre;
            pre = now;
            now = temp;
        }
        return pre;
    }
};
