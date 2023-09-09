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

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find the minimum value node in a BST
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node with a given key from a BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root; // Node not found, return the original root
    }
    
    if (key < root->val) {
        // Key is in the left subtree
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        // Key is in the right subtree
        root->right = deleteNode(root->right, key);
    } else {
        // Key is found, delete this node
        if (root->left == NULL) {
            // Node with only one child or no child
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->val); // Delete the inorder successor
    }
    return root;
}

// Function to create a new TreeNode
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print the BST in-order
void inOrder(struct TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->val);
        inOrder(root->right);
    }
}

int main() {
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->right = createNode(7);

    printf("Original BST: ");
    inOrder(root);
    printf("\n");

    int key1 = 3;
    root = deleteNode(root, key1);
    printf("BST after deleting %d: ", key1);
    inOrder(root);
    printf("\n");

    int key2 = 0;
    root = deleteNode(root, key2);
    printf("BST after deleting %d: ", key2);
    inOrder(root);
    printf("\n");

    return 0;
}

