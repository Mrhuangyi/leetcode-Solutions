/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        if(root == null) {
            return paths;
        }
        List<Integer> values = new ArrayList<>();
        backtracking(root, values, paths);
        return paths;
    }
    private void backtracking(TreeNode node, List<Integer> values, List<String> paths) {
        if(node == null) {
            return;
        }
        values.add(node.val);
        if(isLeaf(node)) {
            paths.add(buildPath(values));
        } else {
            backtracking(node.left, values, paths);
            backtracking(node.right, values, paths);
            
        }
        values.remove(values.size() - 1);
    }
    private boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }
    private String buildPath(List<Integer> values) {
        StringBuilder str = new StringBuilder();
        for(int i = 0; i < values.size(); i++) {
            str.append(values.get(i));
            if(i != values.size() - 1) {
                str.append("->");
            }
        }
        return str.toString();
    }
}
