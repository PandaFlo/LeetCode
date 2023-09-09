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


#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    // Base case: if the root is NULL, return 0 (empty tree)
    if (root == NULL) {
        return 0;
    }

    // Recursive case: calculate the depth of the left and right subtrees
    // and return the maximum depth + 1 (to account for the current level)
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}


int main() {
    // Create the tree: [3,9,20,null,null,15,7]
    struct TreeNode* tree1 = malloc(sizeof(struct TreeNode));
    tree1->val = 3;
    tree1->left = malloc(sizeof(struct TreeNode));
    tree1->left->val = 9;
    tree1->left->left = NULL;
    tree1->left->right = NULL;
    tree1->right = malloc(sizeof(struct TreeNode));
    tree1->right->val = 20;
    tree1->right->left = malloc(sizeof(struct TreeNode));
    tree1->right->left->val = 15;
    tree1->right->left->left = NULL;
    tree1->right->left->right = NULL;
    tree1->right->right = malloc(sizeof(struct TreeNode));
    tree1->right->right->val = 7;
    tree1->right->right->left = NULL;
    tree1->right->right->right = NULL;

    // Calculate the maximum depth for tree1
    int result1 = maxDepth(tree1);
    printf("Maximum Depth of Tree1: %d\n", result1); // Output: 3

    // Create the tree: [1,null,2]
    struct TreeNode* tree2 = malloc(sizeof(struct TreeNode));
    tree2->val = 1;
    tree2->left = NULL;
    tree2->right = malloc(sizeof(struct TreeNode));
    tree2->right->val = 2;
    tree2->right->left = NULL;
    tree2->right->right = NULL;

    // Calculate the maximum depth for tree2
    int result2 = maxDepth(tree2);
    printf("Maximum Depth of Tree2: %d\n", result2); // Output: 2

    // Don't forget to free memory allocated for the trees
    free(tree1->right->right);
    free(tree1->right->left);
    free(tree1->right);
    free(tree1->left);
    free(tree1);

    free(tree2->right);
    free(tree2);

    return 0;
}
