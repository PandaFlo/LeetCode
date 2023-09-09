'''Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
'''


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def goodNodes(self, root):
        def countGoodNodes(node, maxSoFar):
            if not node:
                return 0
            
            count = 0
            if node.val >= maxSoFar:
                count += 1
                maxSoFar = node.val
            
            count += countGoodNodes(node.left, maxSoFar)
            count += countGoodNodes(node.right, maxSoFar)
            
            return count
        
        return countGoodNodes(root, float('-inf'))

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # Test case 1
    root1 = TreeNode(3)
    root1.left = TreeNode(1)
    root1.right = TreeNode(4)
    root1.left.left = TreeNode(3)
    root1.left.right = None
    root1.right.left = TreeNode(1)
    root1.right.right = TreeNode(5)
    
    result1 = solution.goodNodes(root1)
    print("Test Case 1: Number of good nodes:", result1) # Expected: 4

    # Test case 2
    root2 = TreeNode(3)
    root2.left = TreeNode(3)
    root2.right = None
    root2.left.left = TreeNode(4)
    root2.left.right = TreeNode(2)
    
    result2 = solution.goodNodes(root2)
    print("Test Case 2: Number of good nodes:", result2) # Expected: 3

    # Test case 3
    root3 = TreeNode(1)
    
    result3 = solution.goodNodes(root3)
    print("Test Case 3: Number of good nodes:", result3) # Expected: 
