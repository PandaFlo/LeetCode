'''You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

 

Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).


Example 2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).


Example 3:
Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100
'''
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    ans = 0
    
    def rec(self, root, flag_l, ln):
        if root != None:
            ln = ln + 1
            self.ans = ln if self.ans < ln else self.ans
            if root.left != None:
                if flag_l:
                    self.rec(root.left, True, 1)
                else:
                    self.rec(root.left, True, ln)
            if root.right != None:
                if flag_l:
                    self.rec(root.right, False, ln)
                else:
                    self.rec(root.right, False, 1)
    
    def longestZigZag(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 1
        self.rec(root.left, True, 1)
        self.rec(root.right, False, 1)
        return self.ans - 1

# Create test binary trees
# Example 1
#        1
#         \
#          1
#         / \
#        1   1
root1 = TreeNode(1)
root1.right = TreeNode(1)
root1.right.left = TreeNode(1)
root1.right.right = TreeNode(1)
root1.right.left.left = TreeNode(1)

# Example 2
#        1
#       / \
#      1   1
#     /   /
#    1   1
root2 = TreeNode(1)
root2.left = TreeNode(1)
root2.left.left = TreeNode(1)
root2.right = TreeNode(1)
root2.right.left = TreeNode(1)
root2.right.left.left = TreeNode(1)

# Example 3
#        1
root3 = TreeNode(1)

# Initialize the Solution class
solution = Solution()

# Test your function with the sample binary trees
result1 = solution.longestZigZag(root1)
result2 = solution.longestZigZag(root2)
result3 = solution.longestZigZag(root3)

# Print the results
print("Longest ZigZag path length for Example 1:", result1)
print("Longest ZigZag path length for Example 2:", result2)
print("Longest ZigZag path length for Example 3:", result3)
