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



 //Definition for a binary tree node.
 function TreeNode(val, left, right) {
     this.val = (val === undefined ? 0 : val);
     this.left = (left === undefined ? null : left);
     this.right = (right === undefined ? null : right);
  }
 

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    // Base case: if the root is null, return 0 (empty tree)
    if (root === null) {
        return 0;
    }
    
    // Recursive case: calculate the depth of the left and right subtrees
    // and return the maximum depth + 1 (to account for the current level)
    const leftDepth = maxDepth(root.left);
    const rightDepth = maxDepth(root.right);
    
    return Math.max(leftDepth, rightDepth) + 1;
};

// Example usage:
// Create the tree: [3,9,20,null,null,15,7]
const tree = new TreeNode(3);
tree.left = new TreeNode(9);
tree.right = new TreeNode(20);
tree.right.left = new TreeNode(15);
tree.right.right = new TreeNode(7);

// Calculate the maximum depth
const result = maxDepth(tree);
console.log(result); // Output: 3

// Create the tree: [1,null,2]
const tree2 = new TreeNode(1);
tree2.right = new TreeNode(2);

// Calculate the maximum depth
const result2 = maxDepth(tree2);
console.log(result2); // Output: 2
