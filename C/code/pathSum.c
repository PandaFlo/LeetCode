/* Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000
 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int count_paths(struct TreeNode *, int64_t);

int pathSum(struct TreeNode *root, int targetSum){
    int this, left, right;
    
    if (root == NULL)
        return 0;
    this = count_paths(root, targetSum);
    left = pathSum(root->left, targetSum);
    right = pathSum(root->right, targetSum);
    return this + left + right;
}

int count_paths(struct TreeNode *root, int64_t target) {
    int left, right;
    int64_t remaining;
    
    if (root == NULL)
        return 0;
    remaining = target - root->val;
    left = count_paths(root->left, remaining);
    right = count_paths(root->right, remaining);
    return (remaining == 0) ? left + right + 1 : left + right;
}

// Function to free memory for the binary tree
void freeBinaryTree(struct TreeNode *root) {
    if (root == NULL)
        return;
    freeBinaryTree(root->left);
    freeBinaryTree(root->right);
    free(root);
}

int main() {
    // Create the binary tree for the first example
    struct TreeNode *root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(-3);
    root1->left->left = newNode(3);
    root1->left->right = newNode(2);
    root1->right->right = newNode(11);
    root1->left->left->left = newNode(3);
    root1->left->left->right = newNode(-2);
    root1->left->right->right = newNode(1);

    int targetSum1 = 8;
    int result1 = pathSum(root1, targetSum1);
    printf("Test Case 1: %d\n", result1); // Expected output: 3

   // Create the binary tree for the second example
    struct TreeNode *root2 = newNode(5);
    root2->left = newNode(4);
    root2->right = newNode(8);
    root2->left->left = newNode(11);
    root2->left->left->left = newNode(7);
    root2->left->left->right = newNode(2);
    root2->right->right = newNode(4);

    int targetSum2 = 22;
    int result2 = pathSum(root2, targetSum2);
    printf("Test Case 2: %d\n", result2); // Expected output: 3

    // Free the allocated memory for the binary trees
    freeBinaryTree(root1);
    freeBinaryTree(root2);

    return 0;
}
