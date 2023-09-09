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
int maxDepth(TreeNode* root) {
    return (!root) ? 0 : 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

};

int main() {
    // Create the tree: [3,9,20,null,null,15,7]
    TreeNode* tree1 = new TreeNode(3);
    tree1->left = new TreeNode(9);
    tree1->right = new TreeNode(20);
    tree1->right->left = new TreeNode(15);
    tree1->right->right = new TreeNode(7);

    // Create the tree: [1,null,2]
    TreeNode* tree2 = new TreeNode(1);
    tree2->right = new TreeNode(2);

    // Instantiate the Solution class
    Solution solution;

    // Calculate the maximum depth for tree1
    int result1 = solution.maxDepth(tree1);
    std::cout << "Maximum Depth of Tree1: " << result1 << std::endl; // Output: 3

    // Calculate the maximum depth for tree2
    int result2 = solution.maxDepth(tree2);
    std::cout << "Maximum Depth of Tree2: " << result2 << std::endl; // Output: 2

    // Don't forget to free memory allocated for the trees
    delete tree1->right->right;
    delete tree1->right->left;
    delete tree1->right;
    delete tree1->left;
    delete tree1;

    delete tree2->right;
    delete tree2;

    return 0;
}
