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


// Definition for a binary tree node
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function(root1, root2) {
    // Helper function to perform a depth-first traversal and collect leaf values
    function dfs(node, leafValues) {
      if (!node) return;
  
      // If it's a leaf node, add its value to the leafValues array
      if (!node.left && !node.right) {
        leafValues.push(node.val);
        return;
      }
  
      // Recursively traverse left and right subtrees
      dfs(node.left, leafValues);
      dfs(node.right, leafValues);
    }
  
    const leafValues1 = [];
    const leafValues2 = [];
  
    // Traverse both trees and collect their leaf values
    dfs(root1, leafValues1);
    dfs(root2, leafValues2);
  
    // Check if the leaf value sequences are the same
    return JSON.stringify(leafValues1) === JSON.stringify(leafValues2);
  };

  
  function tester() {
    // Define the TreeNode class
    function TreeNode(val, left, right) {
      this.val = val === undefined ? 0 : val;
      this.left = left === undefined ? null : left;
      this.right = right === undefined ? null : right;
    }
  
    // Define the leafSimilar function
    function leafSimilar(root1, root2) {
      // Helper function to perform a depth-first traversal and collect leaf values
      function dfs(node, leafValues) {
        if (!node) return;
  
        // If it's a leaf node, add its value to the leafValues array
        if (!node.left && !node.right) {
          leafValues.push(node.val);
          return;
        }
  
        // Recursively traverse left and right subtrees
        dfs(node.left, leafValues);
        dfs(node.right, leafValues);
      }
  
      const leafValues1 = [];
      const leafValues2 = [];
  
      // Traverse both trees and collect their leaf values
      dfs(root1, leafValues1);
      dfs(root2, leafValues2);
  
      // Check if the leaf value sequences are the same
      return JSON.stringify(leafValues1) === JSON.stringify(leafValues2);
    }
  
    // Example 1: Testing with provided inputs
    const root1Example1 = new TreeNode(
      3,
      new TreeNode(5, new TreeNode(6), new TreeNode(2, null, new TreeNode(7, new TreeNode(4)))),
      new TreeNode(1, new TreeNode(9), new TreeNode(8))
    );
  
    const root2Example1 = new TreeNode(
      3,
      new TreeNode(5, new TreeNode(6), new TreeNode(1, null, new TreeNode(7, new TreeNode(4)))),
      new TreeNode(2, new TreeNode(9), new TreeNode(8))
    );
  
    const resultExample1 = leafSimilar(root1Example1, root2Example1);
    console.log("Example 1 Result:", resultExample1); // It should print "true"
  
    // Example 2: Testing with provided inputs
    const root1Example2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    const root2Example2 = new TreeNode(1, new TreeNode(3), new TreeNode(2));
  
    const resultExample2 = leafSimilar(root1Example2, root2Example2);
    console.log("Example 2 Result:", resultExample2); // It should print "false"
  }
  
  // Call the tester function
  tester();
  