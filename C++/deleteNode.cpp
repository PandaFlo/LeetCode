/* Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.


Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.


Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?
 */


#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Key is found, delete this node
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // In-order traversal to print the BST
    void inOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left);
        std::cout << root->val << " ";
        inOrder(root->right);
    }

    // Clean up the allocated memory
    void cleanUp(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        cleanUp(root->left);
        cleanUp(root->right);
        delete root;
    }
};
int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution solution;

    std::cout << "Original BST: ";
    // Perform an in-order traversal to print the original BST
    solution.inOrder(root);
    std::cout << std::endl;

    int key1 = 3;
    root = solution.deleteNode(root, key1);
    std::cout << "BST after deleting " << key1 << ": ";
    solution.inOrder(root);
    std::cout << std::endl;

    int key2 = 0;
    root = solution.deleteNode(root, key2);
    std::cout << "BST after deleting " << key2 << ": ";
    solution.inOrder(root);
    std::cout << std::endl;

    // Clean up the allocated memory
    solution.cleanUp(root);

    return 0;
}

