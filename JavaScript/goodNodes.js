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
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var goodNodes = function(root) {
    function countGoodNodes(node, maxSoFar) {
        if (!node) {
            return 0;
        }

        let count = 0;
        if (node.val >= maxSoFar) {
            count++;
            maxSoFar = node.val;
        }

        count += countGoodNodes(node.left, maxSoFar);
        count += countGoodNodes(node.right, maxSoFar);

        return count;
    }

    return countGoodNodes(root, Number.NEGATIVE_INFINITY);
};

// Test cases
// Test case 1
var root1 = new TreeNode(3, new TreeNode(1, new TreeNode(3), null), new TreeNode(4, new TreeNode(1), new TreeNode(5)));
var result1 = goodNodes(root1);
console.log("Test Case 1: Number of good nodes:", result1); // Expected: 4

// Test case 2
var root2 = new TreeNode(3, new TreeNode(3, new TreeNode(4), new TreeNode(2)), null);
var result2 = goodNodes(root2);
console.log("Test Case 2: Number of good nodes:", result2); // Expected: 3

// Test case 3
var root3 = new TreeNode(1);
var result3 = goodNodes(root3);
console.log("Test Case 3: Number of good nodes:", result3); // Expected: 1
