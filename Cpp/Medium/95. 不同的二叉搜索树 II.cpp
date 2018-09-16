给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
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
    vector<TreeNode*> vs;
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            return vs;
        } else {
        return generate(1, n);
    }
    }
    vector<TreeNode*> generate(int start, int stop) {
        vector<TreeNode*> vs;
        if(start > stop) {
            vs.push_back(NULL);
            return vs;
        }
        for(int i = start; i <= stop; i++) {
            auto l = generate(start, i - 1);
            auto r = generate(i + 1, stop);
            for(int j = 0; j < l.size(); j++) {
                for(int k = 0; k < r.size(); k++) {
                    TreeNode* n = new TreeNode(i);
                    n->left = l[j];
                    n->right = r[k];
                    vs.push_back(n);
                }
            }
        }
        return vs;
    }
};
