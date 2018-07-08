给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(res,root);
        return res;
    }
    void postorder(vector<int> &res,TreeNode* root){
        if(root==NULL){
            return;
        }
        postorder(res,root->left);
        postorder(res,root->right);
        res.push_back(root->val);
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        s.push(root);
        if(root==NULL){
            return res;
        }
        while(!s.empty()){
            TreeNode *temp = s.top();
            if(temp->left){
                s.push(temp->left);
                temp->left = NULL;
            }else if(temp->right){
                s.push(temp->right);
                temp->right = NULL;
            }else{
                res.push_back(temp->val);
                s.pop();
            }
        }
        return res;
    }
};
