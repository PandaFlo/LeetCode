'''Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000
'''
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def pathSum(self, root, targetSum):
        if not root:
            return 0

        def count_paths(node, remaining):
            if not node:
                return 0

            remaining -= node.val
            path_count = 1 if remaining == 0 else 0

            return path_count + count_paths(node.left, remaining) + count_paths(node.right, remaining)

        return count_paths(root, targetSum) + self.pathSum(root.left, targetSum) + self.pathSum(root.right, targetSum)

# Create the binary tree
# Example tree:        10
#                    /   \
#                   5    -3
#                  / \     \
#                 3   2    11
#                / \   \  
#               3  -2   1
root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(-3)
root.left.left = TreeNode(3)
root.left.right = TreeNode(2)
root.right.right = TreeNode(11)
root.left.left.left = TreeNode(3)
root.left.left.right = TreeNode(-2)
root.left.right.right = TreeNode(1)

# Create a Solution instance
solution = Solution()

# Test the pathSum method
targetSum = 8
result = solution.pathSum(root, targetSum)
print("Number of paths with sum", targetSum, ":", result)
