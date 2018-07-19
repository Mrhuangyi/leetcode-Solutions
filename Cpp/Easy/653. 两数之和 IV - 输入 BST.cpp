给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:

输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

输出: True
 

案例 2:

输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

输出: False
 
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
     unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) {
            return false;
        }
        if(s.count(k - root->val) != 0) {
            return true;
        }
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
