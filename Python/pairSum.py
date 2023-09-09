'''In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

Example 1:

Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 


Example 2:

Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 


Example 3:

Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
 

Constraints:

The number of nodes in the list is an even integer in the range [2, 105].
1 <= Node.val <= 105
'''
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def pairSum(self, head):
        values = []  # Store the values of the linked list
        current = head

        # Step 1: Traverse the linked list and store values
        while current is not None:
            values.append(current.val)
            current = current.next

        left, right = 0, len(values) - 1  # Initialize pointers
        maxTwinSum = 0  # Initialize maximum twin sum

        # Step 3-5: Find maximum twin sum
        while left < right:
            twinSum = values[left] + values[right]
            maxTwinSum = max(maxTwinSum, twinSum)
            left += 1
            right -= 1

        # Step 6: Return the maximum twin sum
        return maxTwinSum

# Helper function to create a linked list from a list of values
def createLinkedList(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

# Test cases
test_cases = [
    [5, 4, 2, 1],  # Expected output: 6
    [4, 2, 2, 3],  # Expected output: 7
    [1, 100000],   # Expected output: 100001
    [1, 2, 3, 4],  # Expected output: 7
    [10, 20, 30, 40, 50],  # Expected output: 60
]

solution = Solution()

for values in test_cases:
    head = createLinkedList(values)
    maxTwinSum = solution.pairSum(head)
    print("Linked List:", values)
    print("Maximum Twin Sum:", maxTwinSum)
    print()
