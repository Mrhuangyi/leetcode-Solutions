给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        TreeNode* node;
        if(root == NULL) {
            return res;
        }
        q.push(root);
        while(!q.empty()) {
            int width = q.size();
            vector<int> temp;
            for(int i = 0; i < width; i++) {
                node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = getHeight(root);
        vector<vector<int>> ret(depth);
        if(depth==0){
            return ret;
        }
        dfs(ret,ret.size()-1,root);
        return ret;
    }
    void dfs(vector<vector<int>>& ret,int level,TreeNode* root){
        if(root==NULL){
            return ;
        }
        ret[level].push_back(root->val);
        dfs(ret,level-1,root->left);
        dfs(ret,level-1,root->right);
    }
    int getHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lside = getHeight(root->left);
        int rside = getHeight(root->right);
        int height = (lside>rside?lside:rside)+1;
        return height;
    }
};
