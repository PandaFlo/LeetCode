/* Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.


Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.


Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?
*/

// TreeNode class (TreeNode.java)
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int x) {
        val = x;
    }
}

// Solution class (Solution.java)
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null; // Base case: empty tree
        }
        
        // If the key is smaller than the root's value, go left
        if (key < root.val) {
            root.left = deleteNode(root.left, key);
        }
        // If the key is larger than the root's value, go right
        else if (key > root.val) {
            root.right = deleteNode(root.right, key);
        }
        else {
            // Node with the key to delete found
            
            // Case 1: Node with only one child or no child
            if (root.left == null) {
                return root.right;
            }
            else if (root.right == null) {
                return root.left;
            }
            
            // Case 2: Node with two children
            root.val = findMin(root.right).val; // Copy the inorder successor's value
            root.right = deleteNode(root.right, root.val); // Delete the inorder successor
        }
        
        return root;
    }
    
    // Helper function to find the minimum value node in a BST
    private TreeNode findMin(TreeNode node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }
}

// Main class (Main.java)
class deleteNode {
    public void inOrder(TreeNode root) {
        if (root == null) return;
        inOrder(root.left);
        System.out.print(root.val + " ");
        inOrder(root.right);
    }

    public static void main(String[] args) {
       deleteNode main = new deleteNode();
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(6);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(4);
        root.right.right = new TreeNode(7);

        System.out.println("Original BST:");
        main.inOrder(root);
        System.out.println();

        int keyToDelete = 3;
        Solution solution = new Solution();
        TreeNode modifiedRoot = solution.deleteNode(root, keyToDelete);

        System.out.println("BST after deleting node with key " + keyToDelete + ":");
        main.inOrder(modifiedRoot);
    }
}


