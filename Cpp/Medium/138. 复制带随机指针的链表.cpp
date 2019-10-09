给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深度拷贝。 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node *cur = head;
        map<Node*, Node*> map;
        //1. 遍历链表，将原节点作为key，拷贝节点作为value保存在map中
        while (cur != nullptr) {
            Node *copy = new Node(cur->val);
            map[cur] = copy;
            cur = cur->next;
        }
        //2. 复制链表next和random指针
        cur = head;
        while (cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};
