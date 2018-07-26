考虑一个二叉树的所有叶子。这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。



举个例子，给定一个如上图所示的树，其叶值序列为 (6, 7, 4, 9, 8) 。

如果两个二叉树的叶值序列相同，我们就认为它们是 叶相似的。

如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，返回 true；否则返回 false 。

 

提示：

给定的两个树会有 1 到 100 个结点。

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
    vector<int> getChildTree(vector<int>& v, TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
        }
        if(root->left != NULL) {
            getChildTree(v, root->left);
        }
        if(root->right != NULL) {
            getChildTree(v, root->right);
        }
        return v;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        a = getChildTree(a, root1);
        b = getChildTree(b, root2);
        if(a.size() != b.size()) {
            return false;
        } else {
            for(int i = 0; i < a.size(); i++) {
                if(a[i] != b[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
