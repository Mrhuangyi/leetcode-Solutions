给定一个N叉树，返回其节点值的前序遍历。

 

例如，给定一个 3叉树 :

 



 

返回其前序遍历: [1,3,5,6,2,4]。

 

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
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
private: 
    void preorder(Node* root, vector<int>& res) {
        if(root == NULL) {
            return;
        }
        res.push_back(root->val);
        for(const auto& n : root->children)
        preorder(n, res);
    }
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
    vector<int> preorder(Node* root) {
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
            for(auto it = node->children.rbegin(); it != node->children.rend(); it++) {
                s.push(*it);
            }
        }
        return res;
    }
};
