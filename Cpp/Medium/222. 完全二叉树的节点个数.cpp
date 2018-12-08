/*

给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6
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
    int countNodes(TreeNode* root) {
        int leftH = leftHeight(root);
        int rightH = rightHeight(root);
        if(leftH == rightH) {
            return pow(2, leftH) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int leftHeight(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + leftHeight(root->left);
    }
    int rightHeight(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + rightHeight(root->right);
    }
};
