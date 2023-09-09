/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
 */


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function definition for lowestCommonAncestor
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Create a sample binary tree (same as Example 1)
    struct TreeNode* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    // Test Example 1: LCA of nodes 5 and 1 should be 3
    struct TreeNode* result1 = lowestCommonAncestor(root, root->left, root->right);
    printf("Example 1 LCA: %d\n", result1->val);  // Output should be 3

    // Test Example 2: LCA of nodes 5 and 4 should be 5
    struct TreeNode* result2 = lowestCommonAncestor(root, root->left, root->left->right->right);
    printf("Example 2 LCA: %d\n", result2->val);  // Output should be 5

    // Create a sample binary tree (same as Example 3)
    struct TreeNode* rootExample3 = newNode(1);
    rootExample3->left = newNode(2);

    // Test Example 3: LCA of nodes 1 and 2 should be 1
    struct TreeNode* result3 = lowestCommonAncestor(rootExample3, rootExample3, rootExample3->left);
    printf("Example 3 LCA: %d\n", result3->val);  // Output should be 1

    // Free the allocated memory
    free(root);
    free(rootExample3);

    return 0;
}
