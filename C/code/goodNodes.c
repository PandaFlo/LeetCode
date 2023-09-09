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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int goodNodes(struct TreeNode* root);

int countGoodNodes(struct TreeNode* node, int maxSoFar) {
    if (!node) {
        return 0;
    }

    int count = 0;
    if (node->val >= maxSoFar) {
        count++;
        maxSoFar = node->val;
    }

    count += countGoodNodes(node->left, maxSoFar);
    count += countGoodNodes(node->right, maxSoFar);

    return count;
}

int goodNodes(struct TreeNode* root) {
    return countGoodNodes(root, INT_MIN);
}

int main() {
    // Test case 1
    struct TreeNode* root1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->val = 3;
    root1->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->left->val = 1;
    root1->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->left->left->val = 3;
    root1->left->left->left = NULL;
    root1->left->left->right = NULL;
    root1->left->right = NULL;
    root1->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->right->val = 4;
    root1->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->right->left->val = 1;
    root1->right->left->left = NULL;
    root1->right->left->right = NULL;
    root1->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->right->right->val = 5;
    root1->right->right->left = NULL;
    root1->right->right->right = NULL;

    int result1 = goodNodes(root1);
    printf("Test Case 1: Number of good nodes: %d\n", result1); // Expected: 4

    // Test case 2
    struct TreeNode* root2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->val = 3;
    root2->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->left->val = 3;
    root2->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->left->left->val = 4;
    root2->left->left->left = NULL;
    root2->left->left->right = NULL;
    root2->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->left->right->val = 2;
    root2->left->right->left = NULL;
    root2->left->right->right = NULL;
    root2->right = NULL;

    int result2 = goodNodes(root2);
    printf("Test Case 2: Number of good nodes: %d\n", result2); // Expected: 3

    // Test case 3
    struct TreeNode* root3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root3->val = 1;
    root3->left = NULL;
    root3->right = NULL;

    int result3 = goodNodes(root3);
    printf("Test Case 3: Number of good nodes: %d\n", result3); // Expected: 1

    // Clean up the memory
    free(root1->right->right);
    free(root1->right->left);
    free(root1->right);
    free(root1->left->left);
    free(root1->left);
    free(root1);
    
    free(root2->left->right);
    free(root2->left->left);
    free(root2->left);
    free(root2);
    
    free(root3);

    return 0;
}
