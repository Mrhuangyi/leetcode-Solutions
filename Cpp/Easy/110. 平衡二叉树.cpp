/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
*/

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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        int temp = abs(depth(root->left) - depth(root->right));
        if(temp > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        return 1 + max(left, right);
    }
};


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
    bool isBalanced(TreeNode* root) {
        return balanceHeight(root)>=0;
    }
    int balanceHeight(TreeNode* root){
        if(root==nullptr) return 0;
        int left = balanceHeight(root->left);
        int right = balanceHeight(root->right);
        if(left<0||right<0||(abs(left-right)>1)) return -1;
        return max(left,right)+1;
    }
};
