给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。

示例 :

输入:

   1
    \
     3
    /
   2

输出:
1

解释:
最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
注意: 树中至少有2个节点。

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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX, pre = -1;
        inorder(root, res, pre);
        return res;
    }
private:
    void inorder(TreeNode* root, int& res, int& pre) {
    if(!root) {
        return;
    }
    inorder(root->left, res, pre);
    if(pre != -1) {
        res = min(res, root->val - pre);
    }
    pre = root->val;
    inorder(root->right, res, pre);
}
};
