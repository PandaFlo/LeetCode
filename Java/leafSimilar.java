/* Consider all the leaves of a binary tree, from left to right order, 
the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Example 1:
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Example 2:
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
 

Constraints:

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
 */
import java.util.ArrayList;
import java.util.List;

/**
 * Definition for a binary tree node.
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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leafValues1 = new ArrayList<>();
        List<Integer> leafValues2 = new ArrayList<>();
        
        // Extract leaf values for both trees
        getLeafValues(root1, leafValues1);
        getLeafValues(root2, leafValues2);
        
        // Check if the leaf value sequences are the same
        return leafValues1.equals(leafValues2);
    }
    
    // Helper function to perform depth-first traversal and extract leaf values
    private void getLeafValues(TreeNode root, List<Integer> leafValues) {
        if (root != null) {
            if (root.left == null && root.right == null) {
                // If it's a leaf node, add its value to the leafValues list
                leafValues.add(root.val);
            }
            getLeafValues(root.left, leafValues);
            getLeafValues(root.right, leafValues);
        }
    }
}

public class leafSimilar {
    public static void main(String[] args) {
        // Create an instance of the Solution class
        Solution solution = new Solution();

// Test case 1
TreeNode root1 = new TreeNode(3);
root1.left = new TreeNode(5);
root1.right = new TreeNode(1);
root1.left.left = new TreeNode(6);
root1.left.right = new TreeNode(2);
root1.left.right.left = new TreeNode(7);
root1.left.right.right = new TreeNode(4);
root1.right.left = null;
root1.right.right = null;

TreeNode root2 = new TreeNode(3);
root2.left = new TreeNode(5);
root2.right = new TreeNode(1);
root2.left.left = new TreeNode(6);
root2.left.right = new TreeNode(2);
root2.left.right.left = new TreeNode(7);
root2.left.right.right = new TreeNode(4);
root2.right.left = null;
root2.right.right = null;


        boolean result1 = solution.leafSimilar(root1, root2);
        System.out.println("Test Case 1: Are the trees leaf-similar? " + result1); // Expected: true

        // Test case 2
        TreeNode root3 = new TreeNode(1);
        root3.left = new TreeNode(2);
        root3.right = new TreeNode(3);

        TreeNode root4 = new TreeNode(1);
        root4.left = new TreeNode(3);
        root4.right = new TreeNode(2);

        boolean result2 = solution.leafSimilar(root3, root4);
        System.out.println("Test Case 2: Are the trees leaf-similar? " + result2); // Expected: false
    }
}
