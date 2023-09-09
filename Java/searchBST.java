/* You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:
Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null || root.val == val) {
            return root;
        }

        if (val < root.val) {
            return searchBST(root.left, val);
        }

        if (val > root.val) {
            return searchBST(root.right, val);
        }

        return null;
    }
}

public class searchBST {
    public static void main(String[] args) {
        // Create a sample binary tree
        //       4
        //      / \
        //     2   7
        //    / \
        //   1   3
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        // Initialize the Solution class
        Solution solution = new Solution();

        // Test case 1: Search for a node with value 2 (node exists)
        int val1 = 2;
        TreeNode result1 = solution.searchBST(root, val1);
        // The result1 should be a reference to the node with value 2

        // Test case 2: Search for a node with value 5 (node doesn't exist)
        int val2 = 5;
        TreeNode result2 = solution.searchBST(root, val2);
        // The result2 should be null because there is no node with value 5 in the tree

        // Output the results
        if (result1 != null) {
            System.out.println("Test case 1 result: " + result1.val);  // Output should be 2
        } else {
            System.out.println("Test case 1 result: Node not found.");
        }

        if (result2 != null) {
            System.out.println("Test case 2 result: " + result2.val);  // Output should be Node not found.
        } else {
            System.out.println("Test case 2 result: Node not found.");
        }
    }
}
