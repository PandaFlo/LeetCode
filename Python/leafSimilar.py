'''Consider all the leaves of a binary tree, from left to right order, 
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
'''
# Definition for a binary tree node
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        def get_leaf_values(node, leaf_values):
            if node:
                get_leaf_values(node.left, leaf_values)
                if not node.left and not node.right:
                    # If it's a leaf node, add its value to the leaf_values list
                    leaf_values.append(node.val)
                get_leaf_values(node.right, leaf_values)
    
        leaf_values1 = []
        leaf_values2 = []
    
        # Extract leaf values for both trees
        get_leaf_values(root1, leaf_values1)
        get_leaf_values(root2, leaf_values2)
    
        # Check if the leaf value sequences are the same
        return leaf_values1 == leaf_values2

if __name__ == "__main__":
    # Example 1
    root1 = TreeNode(3)
    root1.left = TreeNode(5)
    root1.right = TreeNode(1)
    root1.left.left = TreeNode(6)
    root1.left.right = TreeNode(2)
    root1.right.left = TreeNode(9)
    root1.right.right = TreeNode(8)
    root1.left.right.left = TreeNode(7)
    root1.left.right.right = TreeNode(4)

    root2 = TreeNode(3)
    root2.left = TreeNode(5)
    root2.right = TreeNode(1)
    root2.left.left = TreeNode(6)
    root2.left.right = TreeNode(7)
    root2.left.right.right = TreeNode(4)
    root2.left.right.left = TreeNode(2)
    root2.right.left = TreeNode(9)
    root2.right.right = TreeNode(8)

    # Extract leaf values manually
    leaf_values1 = [6, 7, 4, 9, 8]
    leaf_values2 = [6, 7, 4, 9, 8]

    # Compare leaf values
    result = leaf_values1 == leaf_values2
    print("Example 1 Output:", result)

    # Example 2
    root3 = TreeNode(1)
    root3.left = TreeNode(2)
    root3.right = TreeNode(3)

    root4 = TreeNode(1)
    root4.left = TreeNode(3)
    root4.right = TreeNode(2)

    # Extract leaf values manually
    leaf_values3 = [2, 3]
    leaf_values4 = [3, 2]

    # Compare leaf values
    result2 = leaf_values3 == leaf_values4
    print("Example 2 Output:", result2)
