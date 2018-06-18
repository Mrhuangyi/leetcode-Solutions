计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24


递归写法：

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root==NULL){
            return 0;
        }
        if(root->left!=NULL&&root->left->left==NULL&&root->left->right==NULL){
            sum += root->left->val;
        }else{
            sum += sumOfLeftLeaves(root->left);
        }
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};

迭代写法：

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                break;
            }
            if(temp->left){
                q.push(temp->left);
                if(temp->left->left==NULL&&temp->left->right==NULL){
                    sum += temp->left->val;
                }
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        return sum;
    }
};
