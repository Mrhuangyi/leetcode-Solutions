在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：

行数 m 应当等于给定二叉树的高度。
列数 n 应当总是奇数。
根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部分应当有相同的大小。即使一个子树为空而另一个非空，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果两个子树都为空则不需要为它们留出任何空间。
每个未使用的空间应包含一个空的字符串""。
使用相同的规则输出子树。
示例 1:

输入:
     1
    /
   2
输出:
[["", "1", ""],
 ["2", "", ""]]

示例 2:

输入:
     1
    / \
   2   3
    \
     4
输出:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]

示例 3:

输入:
      1
     / \
    2   5
   / 
  3 
 / 
4 
输出:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
注意: 二叉树的高度在范围 [1, 10] 中。


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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        int m = depth(root), n = pow(2, m) - 1;
        for(int i = 0; i < m; i++) {
            res.push_back(vector<string>(n));
        }
        fill(root, res, 0, 0, n);
        return res;
    }
    int depth(TreeNode* node) {
        if(node == NULL) {
            return 0;
        }
        return max(depth(node->left),depth(node->right)) + 1;
    }
    void fill(TreeNode* node, vector<vector<string>> &res, int row, int begin, int end) {
        if(end <= begin || !node) {
            return;
        } else if(end - begin == 1) {
            res[row][begin] = to_string(node->val);
        } else {
            int mid = (end - begin) / 2 + begin;
            res[row][mid] = to_string(node->val);
            fill(node->left, res, row + 1, begin, mid);
            fill(node->right, res, row + 1, mid + 1, end);
        }
        
    }
};
