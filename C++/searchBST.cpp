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


#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: If the root is null or its value is equal to val, return the root
        if (root == nullptr || root->val == val) {
            return root;
        }

        // If val is less than the current root's value, search in the left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }

        // If val is greater than the current root's value, search in the right subtree
        if (val > root->val) {
            return searchBST(root->right, val);
        }

        // If val is not found, return nullptr
        return nullptr;
    }
};

int main() {
    // Create a sample binary search tree
    //       4
    //      / \
    //     2   7
    //    / \
    //   1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Initialize the Solution class
    Solution solution;

    // Test case 1: Search for a node with value 2 (node exists)
    int val1 = 2;
    TreeNode* result1 = solution.searchBST(root, val1);
    // The result1 should be a pointer to the node with value 2

    // Test case 2: Search for a node with value 5 (node doesn't exist)
    int val2 = 5;
    TreeNode* result2 = solution.searchBST(root, val2);
    // The result2 should be nullptr because there is no node with value 5 in the tree

    // Output the results
    if (result1) {
        std::cout << "Test case 1 result: " << result1->val << std::endl;  // Output should be 2
    } else {
        std::cout << "Test case 1 result: Node not found." << std::endl;
    }

    if (result2) {
        std::cout << "Test case 2 result: " << result2->val << std::endl;  // Output should be Node not found.
    } else {
        std::cout << "Test case 2 result: Node not found." << std::endl;
    }

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
