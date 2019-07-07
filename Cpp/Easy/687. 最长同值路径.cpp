给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:

2
示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出:

2

注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。


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
    int res = 0;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(root->left != NULL && root->left->val == root->val) {
            left++;
        } else {
            left = 0;
        }
        if(root->right != NULL && root->right->val == root->val) {
            right++;
        } else {
            right = 0;
        }
        res = max(res, left + right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        dfs(root);
        return res;
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
    int longestUnivaluePath(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int sub = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(sub, dfs(root->left, root->val) + dfs(root->right, root->val));
    }
    int dfs(TreeNode* node, int parent) {
        if(!node || node->val != parent) {
            return 0;
        }
        return 1 + max(dfs(node->left, node->val), dfs(node->right, node->val));
    }
};
