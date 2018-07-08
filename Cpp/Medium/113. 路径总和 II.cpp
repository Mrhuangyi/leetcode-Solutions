给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        pathSum(root,sum,cur,res);
        return res;
    }
    private:
        void pathSum(TreeNode *root,int gap,vector<int> &cur,vector<vector<int>> &res){
            if(root==NULL){
                return;
            }
            cur.push_back(root->val);
            if(root->left==NULL&&root->right==NULL){
                if(gap==root->val){
                    res.push_back(cur);
                }
            }
            pathSum(root->left,gap-root->val,cur,res);
            pathSum(root->right,gap-root->val,cur,res);
            cur.pop_back();
        }
};
