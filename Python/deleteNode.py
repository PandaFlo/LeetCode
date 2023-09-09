'''Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

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
'''

class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        # Helper function to find the minimum node in a BST
        def find_min(node):
            while node.left:
                node = node.left
            return node

        # Base case: If the root is None, return None
        if not root:
            return root

        # If the key is smaller than the root's key, recursively delete from the left subtree.
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        # If the key is larger than the root's key, recursively delete from the right subtree.
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        # If the key is equal to the root's key, then this is the node to be deleted.
        else:
            # Node with only one child or no child
            if not root.left:
                return root.right
            elif not root.right:
                return root.left

            # Node with two children: get the inorder successor (smallest in the right subtree)
            min_node = find_min(root.right)
            root.val = min_node.val
            # Delete the inorder successor
            root.right = self.deleteNode(root.right, min_node.val)

        return root

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Helper function to perform an in-order traversal of the tree
def in_order_traversal(root):
    if root:
        in_order_traversal(root.left)
        print(root.val)
        in_order_traversal(root.right)

# Create a sample binary search tree
root = TreeNode(5)
root.left = TreeNode(3)
root.right = TreeNode(6)
root.left.left = TreeNode(2)
root.left.right = TreeNode(4)
root.right.right = TreeNode(7)

# Print the original tree
print("Original Tree:")
in_order_traversal(root)

# Create a Solution instance
solution = Solution()

# Delete a node with a specified key (e.g., 3)
key_to_delete = 3
root = solution.deleteNode(root, key_to_delete)

# Print the tree after deletion
print("\nTree After Deletion:")
in_order_traversal(root)
