/* Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3


Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
 */


 // Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int maxDepth(TreeNode root) {
        // Base case: if the root is null, return 0 (empty tree)
        if (root == null) {
            return 0;
        }

        // Recursive case: calculate the depth of the left and right subtrees
        // and return the maximum depth + 1 (to account for the current level)
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);

        return Math.max(leftDepth, rightDepth) + 1;
    }

}

    public class maxDepth {
    // Tester
    public static void main(String[] args) {
        // Create the tree: [3,9,20,null,null,15,7]
        TreeNode tree1 = new TreeNode(3);
        tree1.left = new TreeNode(9);
        tree1.right = new TreeNode(20);
        tree1.right.left = new TreeNode(15);
        tree1.right.right = new TreeNode(7);

        // Calculate the maximum depth
        Solution solution = new Solution();
        int result1 = solution.maxDepth(tree1);
        System.out.println(result1); // Output: 3

        // Create the tree: [1,null,2]
        TreeNode tree2 = new TreeNode(1);
        tree2.right = new TreeNode(2);

        // Calculate the maximum depth
        int result2 = solution.maxDepth(tree2);
        System.out.println(result2); // Output: 2
    }
}
