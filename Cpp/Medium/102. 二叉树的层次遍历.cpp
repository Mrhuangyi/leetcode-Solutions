给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        if(root==NULL){
            return res;
        }
        while(!q.empty()){
            queue<TreeNode*> qt;
            vector<int> v;
        while(!q.empty()){
            TreeNode* now = q.front();
            q.pop();
            v.push_back(now->val);
            if(now->left!=NULL){
                qt.push(now->left);
            }
            if(now->right!=NULL){
                qt.push(now->right);
            }
        }
              res.push_back(v);
            q = qt;
        }
        return res;
    }
};
