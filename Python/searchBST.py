'''You are given the root of a binary search tree (BST) and an integer val.

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
'''
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def searchBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if root is None:
            return None
        
        if root.val == val:
            return root
        elif root.val < val:
            return self.searchBST(root.right, val)
        else:
            return self.searchBST(root.left, val)

# Example test cases
# Create a sample binary search tree
#       4
#      / \
#     2   7
#    / \
#   1   3
root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(7)
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)

# Initialize the Solution class
solution = Solution()

# Test case 1: Search for a node with value 2 (node exists)
result1 = solution.searchBST(root, 2)
# The result should be a subtree rooted at the node with value 2
# The tree should look like:
#   2
#  / \
# 1   3

# Test case 2: Search for a node with value 5 (node doesn't exist)
result2 = solution.searchBST(root, 5)
# The result should be None because there is no node with value 5 in the tree

# Print the results
if result1:
    print("Test case 1 result:", result1.val)  # Output should be 2
else:
    print("Test case 1 result: Node not found.")

if result2:
    print("Test case 2 result:", result2.val)  # This should not be executed
else:
    print("Test case 2 result: Node not found.")
