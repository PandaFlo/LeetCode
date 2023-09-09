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
#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int maxZigZag = 0;
        longestZigZagHelper(root, true, 0, maxZigZag);  // Start with left direction
        longestZigZagHelper(root, false, 0, maxZigZag); // Start with right direction
        return maxZigZag;
    }

private:
    void longestZigZagHelper(TreeNode* node, bool isLeft, int length, int& maxZigZag) {
        if (!node) {
            return;
        }

        maxZigZag = std::max(maxZigZag, length);

        if (isLeft) {
            // If current direction is left, move to the left child with a new direction
            longestZigZagHelper(node->left, true, length + 1, maxZigZag);
            // Reset the length if moving in the opposite direction
            longestZigZagHelper(node->right, false, 1, maxZigZag);
        } else {
            // If current direction is right, move to the right child with a new direction
            longestZigZagHelper(node->right, false, length + 1, maxZigZag);
            // Reset the length if moving in the opposite direction
            longestZigZagHelper(node->left, true, 1, maxZigZag);
        }
    }
};

int main() {
    Solution solution;

    // Create Example 1: [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(1);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(1);
    root1->right->right->right = new TreeNode(1);

    int result1 = solution.longestZigZag(root1);
    std::cout << "Example 1: " << result1 << std::endl;  // Output should be 2

    // Create Example 2: [1,1,1,null,1,null,null,1,1,null,1]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(1);
    root2->left->left->right = new TreeNode(1);

    int result2 = solution.longestZigZag(root2);
    std::cout << "Example 2: " << result2 << std::endl;  // Output should be 3

    // Create Example 3: [1]
    TreeNode* root3 = new TreeNode(1);

    int result3 = solution.longestZigZag(root3);
    std::cout << "Example 3: " << result3 << std::endl;  // Output should be 0

    // Clean up memory
    delete root1;
    delete root2;
    delete root3;

    return 0;
}
