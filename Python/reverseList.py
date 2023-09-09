'''Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?�>���'''


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def reverseList(self, head):
        prev = None
        current = head
        
        while current is not None:
            nextNode = current.next
            current.next = prev
            prev = current
            current = nextNode
        
        return prev

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

# Helper function to print a linked list
def printLinkedList(head):
    current = head  
    while current is not None:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

# Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
originalList = createLinkedList([1, 2, 3, 4, 5])

# Create a Solution object
solution = Solution()

# Reverse the linked list
reversedList = solution.reverseList(originalList)

# Print the reversed linked list
printLinkedList(reversedList)
