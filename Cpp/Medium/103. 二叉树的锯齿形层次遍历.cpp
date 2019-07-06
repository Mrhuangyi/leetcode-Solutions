给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        TreeNode* p;
        q.push(root);
        int flag = 0;
        while(!q.empty()) {
            vector<int> temp;
            int width = q.size();
            for(int i = 0; i < width; i++) {
                p = q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left) {
                    q.push(p->left);
                }
                if(p->right) {
                    q.push(p->right);
                }
                
            }
            if(flag % 2 == 1) {
                reverse(temp.begin(), temp.end());
            }
            flag++;
            res.push_back(temp);
        }
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
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        build(root, 1);
        for(int i = 1; i < res.size(); i+=2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    void build(TreeNode* node, int level) {
        if(!node) {
            return;
        }
        if(res.size() <= level - 1) {
            res.push_back(vector<int>());
        }
        res[level - 1].push_back(node->val);
        if(node->left) {
            build(node->left, level + 1);
        }
        if(node->right) {
            build(node->right,level + 1);
        }
    }
};
