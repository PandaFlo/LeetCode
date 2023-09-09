/* You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

 

Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).


Example 2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).


Example 3:
Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100
 */
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

enum Child {
    Child_LEFT,
    Child_RIGHT
};

static int g_maxZigzagLen;

static void longestZigZag_recurse(
    const struct TreeNode* const pNode,
    const enum Child child,
    const int visitedCnt
) {
    if (NULL == pNode) {
        g_maxZigzagLen = visitedCnt > g_maxZigzagLen ? visitedCnt : g_maxZigzagLen;
        return;
    }

    switch (child) {
    case Child_LEFT:
        longestZigZag_recurse(pNode->left, Child_RIGHT, visitedCnt + 1);
        longestZigZag_recurse(pNode->right, Child_LEFT, 1);
        break;
    case Child_RIGHT:
        longestZigZag_recurse(pNode->left, Child_LEFT, 1);
        longestZigZag_recurse(pNode->right, Child_RIGHT, visitedCnt + 1);
        break;
    }
}

int longestZigZag(const struct TreeNode* const pRoot) {
    g_maxZigzagLen = 0;
    longestZigZag_recurse(pRoot, Child_LEFT, 1);
    longestZigZag_recurse(pRoot, Child_RIGHT, 1);
    return g_maxZigzagLen - 1; // Return the correct ZigZag path length.
}

int main() {
    // Example 1
    struct TreeNode* root1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->val = 1;
    root1->left = NULL;
    root1->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->right->val = 1;
    root1->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->right->left->val = 1;
    root1->right->left->left = NULL;
    root1->right->left->right = NULL;
    root1->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->right->right->val = 1;
    root1->right->right->left = NULL;
    root1->right->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->right->right->right->val = 1;
    root1->right->right->right->left = NULL;
    root1->right->right->right->right = NULL;

    int longestPath1 = longestZigZag(root1);
    printf("Longest ZigZag path length for Example 1: %d\n", longestPath1);

    // Free memory for Example 1
    free(root1->right->right->right->right);
    free(root1->right->right->right);
    free(root1->right->right);
    free(root1->right->left);
    free(root1->right);
    free(root1);

    // Example 2
    struct TreeNode* root2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->val = 1;
    root2->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->left->val = 1;
    root2->left->left = NULL;
    root2->left->right = NULL;
    root2->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->right->val = 1;
    root2->right->left = NULL;
    root2->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root2->right->right->val = 1;
    root2->right->right->left = NULL;
    root2->right->right->right = NULL;

    int longestPath2 = longestZigZag(root2);
    printf("Longest ZigZag path length for Example 2: %d\n", longestPath2);

    // Free memory for Example 2
    free(root2->right->right);
    free(root2->right);
    free(root2->left);
    free(root2);

    // Example 3
    struct TreeNode* root3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root3->val = 1;
    root3->left = NULL;
    root3->right = NULL;

    int longestPath3 = longestZigZag(root3);
    printf("Longest ZigZag path length for Example 3: %d\n", longestPath3);

    // Free memory for Example 3
    free(root3);

    return 0;
}
