给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
      
      
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
    void flatten(TreeNode* root) {
        if(!root) {
            return;
        }
        vector<TreeNode* > res;
        TreeNode dummy(0);
        TreeNode* n = &dummy;
        res.push_back(root);
        while(!res.empty()) {
            TreeNode* p = res.back();
            res.pop_back();
            n->right = p;
            n = p;
            if(p->right) {
                res.push_back(p->right);
                p->right = NULL;
            }
            if(p->left) {
                res.push_back(p->left);
                p->left = NULL;
            }
        } 
    }
};
