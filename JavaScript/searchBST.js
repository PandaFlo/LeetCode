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
// Definition for a binary tree node.
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

// Function to search for a node with a specified value in a BST
var searchBST = function(root, val) {
    // Base case: if the root is null or its value is equal to val, return the root
    if (root === null || root.val === val) {
        return root;
    }
    
    // If val is less than the current root's value, search in the left subtree
    if (val < root.val) {
        return searchBST(root.left, val);
    }
    
    // If val is greater than the current root's value, search in the right subtree
    if (val > root.val) {
        return searchBST(root.right, val);
    }
    
    // If val is not found, return null
    return null;
};


// Create a sample binary search tree
//       4
//      / \
//     2   7
//    / \
//   1   3
var root = new TreeNode(4);
root.left = new TreeNode(2);
root.right = new TreeNode(7);
root.left.left = new TreeNode(1);
root.left.right = new TreeNode(3);

// Test case 1: Search for a node with value 2 (node exists)
var result1 = searchBST(root, 2);
// The result1 should be a subtree rooted at the node with value 2
// The tree should look like:
//   2
//  / \
// 1   3

// Test case 2: Search for a node with value 5 (node doesn't exist)
var result2 = searchBST(root, 5);
// The result2 should be null because there is no node with value 5 in the tree

// Output the results
console.log("Test case 1 result:", result1);
console.log("Test case 2 result:", result2);


