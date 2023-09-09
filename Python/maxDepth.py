'''Given the root of a binary tree, return its maximum depth.

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
'''

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # Base case: if the root is None, return 0 (empty tree)
        if root is None:
            return 0

        # Recursive case: calculate the depth of the left and right subtrees
        # and return the maximum depth + 1 (to account for the current level)
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)

        return max(left_depth, right_depth) + 1

# Create the tree: [3,9,20,null,null,15,7]
tree1 = TreeNode(3)
tree1.left = TreeNode(9)
tree1.right = TreeNode(20)
tree1.right.left = TreeNode(15)
tree1.right.right = TreeNode(7)

# Create the tree: [1,null,2]
tree2 = TreeNode(1)
tree2.right = TreeNode(2)

# Instantiate the Solution class
solution = Solution()

# Calculate the maximum depth for tree1
result1 = solution.maxDepth(tree1)
print(result1)  # Output: 3

# Calculate the maximum depth for tree2
result2 = solution.maxDepth(tree2)
print(result2)  # Output: 2
