'''Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

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
'''
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        # Base case: if the root is None or one of the nodes is found, return the root
        if root is None or root == p or root == q:
            return root
        
        # Recursively search for the nodes in the left and right subtrees
        left_lca = self.lowestCommonAncestor(root.left, p, q)
        right_lca = self.lowestCommonAncestor(root.right, p, q)
        
        # If both nodes are found in different subtrees, the current root is the LCA
        if left_lca and right_lca:
            return root
        # If only one node is found in one of the subtrees, propagate it up
        return left_lca or right_lca

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# Create the binary tree from Example 1
root = TreeNode(3)
root.left = TreeNode(5)
root.right = TreeNode(1)
root.left.left = TreeNode(6)
root.left.right = TreeNode(2)
root.right.left = TreeNode(0)
root.right.right = TreeNode(8)
root.left.right.left = TreeNode(7)
root.left.right.right = TreeNode(4)

# Create a Solution object
solution = Solution()

# Test with Example 1 inputs
result = solution.lowestCommonAncestor(root, root.left, root.right)
print("Example 1 LCA:", result.val)  # Output should be 3

# Test with Example 2 inputs
result = solution.lowestCommonAncestor(root, root.left, root.left.right.right)
print("Example 2 LCA:", result.val)  # Output should be 5

# Create a new binary tree for Example 3
root_example3 = TreeNode(1)
root_example3.left = TreeNode(2)

# Test with Example 3 inputs and the new tree
result_example3 = solution.lowestCommonAncestor(root_example3, root_example3, root_example3.left)
print("Example 3 LCA:", result_example3.val)  # Output should be 1
