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

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Helper function to perform depth-first traversal and extract leaf values
void getLeafValues(struct TreeNode* root, int* leafValues, int* index) {
    if (root) {
        if (!root->left && !root->right) {
            // If it's a leaf node, add its value to the leafValues array
            leafValues[(*index)++] = root->val;
        }
        getLeafValues(root->left, leafValues, index);
        getLeafValues(root->right, leafValues, index);
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leafValues1[200]; // Assuming the maximum number of leaves is 200
    int leafValues2[200]; // Assuming the maximum number of leaves is 200
    int index1 = 0;
    int index2 = 0;

    // Extract leaf values for both trees
    getLeafValues(root1, leafValues1, &index1);
    getLeafValues(root2, leafValues2, &index2);

    // Check if the leaf value sequences are the same
    if (index1 != index2) {
        return false;
    }

    for (int i = 0; i < index1; i++) {
        if (leafValues1[i] != leafValues2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    // Example 1
    struct TreeNode* root1 = malloc(sizeof(struct TreeNode));
    root1->val = 3;
    root1->left = malloc(sizeof(struct TreeNode));
    root1->left->val = 5;
    root1->left->left = malloc(sizeof(struct TreeNode));
    root1->left->left->val = 6;
    root1->left->right = malloc(sizeof(struct TreeNode));
    root1->left->right->val = 2;
    root1->right = malloc(sizeof(struct TreeNode));
    root1->right->val = 1;
    root1->right->left = malloc(sizeof(struct TreeNode));
    root1->right->left->val = 9;
    root1->right->right = malloc(sizeof(struct TreeNode));
    root1->right->right->val = 8;
    root1->left->right->left = malloc(sizeof(struct TreeNode));
    root1->left->right->left->val = 7;
    root1->left->right->right = malloc(sizeof(struct TreeNode));
    root1->left->right->right->val = 4;
    root1->left->left->left = NULL;
    root1->left->left->right = NULL;
    root1->left->right->left->left = NULL;
    root1->left->right->left->right = NULL;
    root1->left->right->right->left = NULL;
    root1->left->right->right->right = NULL;
    root1->right->left->left = NULL;
    root1->right->left->right = NULL;
    root1->right->right->left = NULL;
    root1->right->right->right = NULL;

    struct TreeNode* root2 = malloc(sizeof(struct TreeNode));
    root2->val = 3;
    root2->left = malloc(sizeof(struct TreeNode));
    root2->left->val = 5;
    root2->left->left = malloc(sizeof(struct TreeNode));
    root2->left->left->val = 6;
    root2->left->right = malloc(sizeof(struct TreeNode));
    root2->left->right->val = 2;
    root2->right = malloc(sizeof(struct TreeNode));
    root2->right->val = 1;
    root2->right->left = malloc(sizeof(struct TreeNode));
    root2->right->left->val = 9;
    root2->right->right = malloc(sizeof(struct TreeNode));
    root2->right->right->val = 8;
    root2->left->right->left = malloc(sizeof(struct TreeNode));
    root2->left->right->left->val = 7;
    root2->left->right->right = malloc(sizeof(struct TreeNode));
    root2->left->right->right->val = 4;
    root2->left->left->left = NULL;
    root2->left->left->right = NULL;
    root2->left->right->left->left = NULL;
    root2->left->right->left->right = NULL;
    root2->left->right->right->left = NULL;
    root2->left->right->right->right = NULL;
    root2->right->left->left = NULL;
    root2->right->left->right = NULL;
    root2->right->right->left = NULL;
    root2->right->right->right = NULL;

    bool result = leafSimilar(root1, root2);
    printf("Example 1 Output: %s\n", result ? "true" : "false");

    // Example 2
    struct TreeNode* root3 = malloc(sizeof(struct TreeNode));
    root3->val = 1;
    root3->left = malloc(sizeof(struct TreeNode));
    root3->left->val = 2;
    root3->right = malloc(sizeof(struct TreeNode));
    root3->right->val = 3;
    root3->left->left = NULL;
    root3->left->right = NULL;
    root3->right->left = NULL;
    root3->right->right = NULL;

    struct TreeNode* root4 = malloc(sizeof(struct TreeNode));
    root4->val = 1;
    root4->left = malloc(sizeof(struct TreeNode));
    root4->left->val = 3;
    root4->right = malloc(sizeof(struct TreeNode));
    root4->right->val = 2;
    root4->left->left = NULL;
    root4->left->right = NULL;
    root4->right->left = NULL;
    root4->right->right = NULL;

    bool result2 = leafSimilar(root3, root4);
    printf("Example 2 Output: %s\n", result2 ? "true" : "false");

    // Free the allocated memory
    free(root1);
    free(root2);
    free(root3);
    free(root4);

    return 0;
}
