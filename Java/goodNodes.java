/* Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
 */





 
 // Definition for a binary tree node.
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
    public int goodNodes(TreeNode root) {
        return countGoodNodes(root, Integer.MIN_VALUE);
    }
    
    private int countGoodNodes(TreeNode node, int maxSoFar) {
        if (node == null) {
            return 0;
        }
        
        int count = 0;
        if (node.val >= maxSoFar) {
            count++;
            maxSoFar = node.val;
        }
        
        count += countGoodNodes(node.left, maxSoFar);
        count += countGoodNodes(node.right, maxSoFar);
        
        return count;
    }
}


public class goodNodes {
    public static void main(String[] args) {
        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Test case 1
        TreeNode root1 = new TreeNode(3);
        root1.left = new TreeNode(1);
        root1.right = new TreeNode(4);
        root1.left.left = new TreeNode(3);
        root1.left.right = null;
        root1.right.left = new TreeNode(1);
        root1.right.right = new TreeNode(5);

        int result1 = solution.goodNodes(root1);
        System.out.println("Test Case 1: Number of good nodes: " + result1); // Expected: 4

        // Test case 2
        TreeNode root2 = new TreeNode(3);
        root2.left = new TreeNode(3);
        root2.right = null;
        root2.left.left = new TreeNode(4);
        root2.left.right = new TreeNode(2);

        int result2 = solution.goodNodes(root2);
        System.out.println("Test Case 2: Number of good nodes: " + result2); // Expected: 3

        // Test case 3
        TreeNode root3 = new TreeNode(1);

        int result3 = solution.goodNodes(root3);
        System.out.println("Test Case 3: Number of good nodes: " + result3); // Expected: 1
    }
}
