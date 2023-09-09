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


#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }

        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree (same as Example 1)
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Test Example 1: LCA of nodes 5 and 1 should be 3
    TreeNode* result1 = solution.lowestCommonAncestor(root, root->left, root->right);
    std::cout << "Example 1 LCA: " << result1->val << std::endl;  // Output should be 3

    // Test Example 2: LCA of nodes 5 and 4 should be 5
    TreeNode* result2 = solution.lowestCommonAncestor(root, root->left, root->left->right->right);
    std::cout << "Example 2 LCA: " << result2->val << std::endl;  // Output should be 5

    // Create a sample binary tree (same as Example 3)
    TreeNode* rootExample3 = new TreeNode(1);
    rootExample3->left = new TreeNode(2);

    // Test Example 3: LCA of nodes 1 and 2 should be 1
    TreeNode* result3 = solution.lowestCommonAncestor(rootExample3, rootExample3, rootExample3->left);
    std::cout << "Example 3 LCA: " << result3->val << std::endl;  // Output should be 1

    // Clean up memory
    delete root;
    delete rootExample3;

    return 0;
}
