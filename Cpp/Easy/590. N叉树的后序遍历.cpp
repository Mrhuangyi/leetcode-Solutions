给定一个N叉树，返回其节点值的后序遍历。

 

例如，给定一个 3叉树 :

 



 

返回其后序遍历: [5,6,3,2,4,1].

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?


递归法：

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL) {
            return res;
        } else {
        for(auto n : root->children)
        postorder(n);
        res.push_back(root->val);
        }
            return res;
    }
private:
    vector<int> res;
};

迭代法：

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node* node = s.top();
            s.pop();
            res.push_back(node->val);
            for(auto n : node->children) {
                s.push(n);
            }
        }
        reverse(res.begin(), res.end());
            return res;
    }
};
