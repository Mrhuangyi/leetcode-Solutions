给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.

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
    int minDepth(TreeNode* root) {
        return minDepth(root,false);
    }
private:
    static int minDepth(TreeNode *root,bool hasbrother){
        if(!root) return hasbrother ? INT_MAX:0;
        return 1+min(minDepth(root->left,root->right!=NULL),minDepth(root->right,root->left!=NULL));
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
    int minDepth(TreeNode* root) {
         if(root==nullptr){
             return 0;
         }
        int result = INT_MAX;
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(root,1));
        while(!s.empty()){
            auto node = s.top().first;
            auto depth = s.top().second;
            s.pop();
            if(node->left==nullptr&&node->right==nullptr){
                result = min(result,depth);
            }
            if(node->left&&result>depth){
                s.push(make_pair(node->left,depth+1));
            }
            if(node->right&&result>depth){
                s.push(make_pair(node->right,depth+1));
            }
        }
        return result;
    }
};
