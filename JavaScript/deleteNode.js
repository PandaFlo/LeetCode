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


function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

/**
 * @param {TreeNode} root
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
    if (!root) {
        return root;
    }

    // If the key is smaller than the root's key, recursively delete from the left subtree.
    if (key < root.val) {
        root.left = deleteNode(root.left, key);
    }
    // If the key is larger than the root's key, recursively delete from the right subtree.
    else if (key > root.val) {
        root.right = deleteNode(root.right, key);
    }
    // If the key is equal to the root's key, then this is the node to be deleted.
    else {
        // Node with only one child or no child
        if (!root.left) {
            return root.right;
        } else if (!root.right) {
            return root.left;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        root.val = findMinValue(root.right);

        // Delete the inorder successor
        root.right = deleteNode(root.right, root.val);
    }
    return root;
};

// Helper function to find the smallest value in a BST
function findMinValue(node) {
    while (node.left) {
        node = node.left;
    }
    return node.val;
}

// Helper function to insert values into a BST
function insert(root, key) {
    if (!root) {
        return new TreeNode(key);
    }

    if (key < root.val) {
        root.left = insert(root.left, key);
    } else if (key > root.val) {
        root.right = insert(root.right, key);
    }

    return root;
}

// Helper function to print the BST in-order
function inOrderTraversal(root) {
    if (root) {
        inOrderTraversal(root.left);
        console.log(root.val);
        inOrderTraversal(root.right);
    }
}

// Create a sample BST
var root = null;
root = insert(root, 5);
root = insert(root, 3);
root = insert(root, 6);
root = insert(root, 2);
root = insert(root, 4);
root = insert(root, 7);

console.log("Original BST:");
inOrderTraversal(root);

// Delete a node from the BST
var keyToDelete = 3;
root = deleteNode(root, keyToDelete);

console.log("BST after deleting", keyToDelete + ":");
inOrderTraversal(root);

