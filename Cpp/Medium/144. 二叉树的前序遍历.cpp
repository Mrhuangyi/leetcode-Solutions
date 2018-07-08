给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

递归法：

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(res,root);
        return res;
    }
    void preorder(vector<int> &res,TreeNode* root){
        if(root==NULL){
            return ;
        }
        res.push_back(root->val);
        preorder(res,root->left);
        preorder(res,root->right);
    }
};

迭代法：

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        if(root!=NULL){
            s.push(root);
        }
        while(!s.empty()){
            TreeNode *p = s.top();
            s.pop();
            res.push_back(p->val);
            if(p->right!=NULL){
                s.push(p->right);
            }
            if(p->left!=NULL){
                s.push(p->left);
            }
        }
        return res;
    
    }
};
