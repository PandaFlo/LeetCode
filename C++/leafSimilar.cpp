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


 // Definition for a binary tree node.
#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to perform depth-first traversal and extract leaf values
    void getLeafValues(TreeNode* root, vector<int>& leafValues) {
        if (root) {
            if (!root->left && !root->right) {
                // If it's a leaf node, add its value to the leafValues vector
                leafValues.push_back(root->val);
            }
            getLeafValues(root->left, leafValues);
            getLeafValues(root->right, leafValues);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValues1, leafValues2;

        // Extract leaf values for both trees
        getLeafValues(root1, leafValues1);
        getLeafValues(root2, leafValues2);

        // Check if the leaf value sequences are the same
        return leafValues1 == leafValues2;
    }
};

int main() {
    // Example 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(2);
    root2->right->left = new TreeNode(9);
    root2->right->right = new TreeNode(8);
    root2->left->right->left = new TreeNode(7);
    root2->left->right->right = new TreeNode(4);

    Solution solution;
    bool result = solution.leafSimilar(root1, root2);
    cout << "Example 1 Output: " << boolalpha << result << endl;

    // Example 2
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(3);
    root4->right = new TreeNode(2);

    bool result2 = solution.leafSimilar(root3, root4);
    cout << "Example 2 Output: " << boolalpha << result2 << endl;

    return 0;
}
