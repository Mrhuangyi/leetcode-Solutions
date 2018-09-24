给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深度拷贝。 

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        RandomListNode dummy(0);
        RandomListNode* n = &dummy;
        RandomListNode* h = head;
        map<RandomListNode*, RandomListNode*> m;
        while(h) {
            RandomListNode* node = new RandomListNode(h->label);
            n->next = node;
            n = node;
            node->random = h->random;
            m[h] = node;
            h = h->next;
        }
        h = dummy.next;
        while(h) {
            if(h->random != NULL) {
                h->random = m[h->random];
            }
            h = h->next;
        }
        return dummy.next;
    }
};
