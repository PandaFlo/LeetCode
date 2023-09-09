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


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to search for a node with a specified value in a BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    }

    if (val > root->val) {
        return searchBST(root->right, val);
    }

    return NULL;
}

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Create a sample binary search tree
    //       4
    //      / \
    //     2   7
    //    / \
    //   1   3
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    // Test case 1: Search for a node with value 2 (node exists)
    int val1 = 2;
    struct TreeNode* result1 = searchBST(root, val1);
    // The result1 should be a pointer to the node with value 2

    // Test case 2: Search for a node with value 5 (node doesn't exist)
    int val2 = 5;
    struct TreeNode* result2 = searchBST(root, val2);
    // The result2 should be NULL because there is no node with value 5 in the tree

    // Output the results
    if (result1) {
        printf("Test case 1 result: %d\n", result1->val);  // Output should be 2
    } else {
        printf("Test case 1 result: Node not found.\n");
    }

    if (result2) {
        printf("Test case 2 result: %d\n", result2->val);  // Output should be Node not found.
    } else {
        printf("Test case 2 result: Node not found.\n");
    }

    // Free allocated memory
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
