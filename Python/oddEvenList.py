'''Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]


Example 2:

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-10^6 <= Node.val <= 10^6
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        
        odd_head = odd_curr = head
        even_head = even_curr = head.next
        
        curr = head.next.next
        index = 3  # Start with the third node (1-indexed)
        
        while curr:
            if index % 2 == 1:
                odd_curr.next = curr
                odd_curr = odd_curr.next
            else:
                even_curr.next = curr
                even_curr = even_curr.next
            curr = curr.next
            index += 1
        
        odd_curr.next = even_head
        even_curr.next = None  # Set the next of the last even node to None
        
        return odd_head

# Helper function to create a linked list from a list of values
def create_linked_list(values):
    dummy = ListNode()
    curr = dummy
    for val in values:
        curr.next = ListNode(val)
        curr = curr.next
    return dummy.next

# Helper function to convert linked list to list for comparison
def linked_list_to_list(head):
    result = []
    curr = head
    while curr:
        result.append(curr.val)
        curr = curr.next
    return result

# Test cases
test_cases = [
    [1, 2, 3, 4, 5],
    [2, 1, 3, 5, 6, 4, 7]
]

solution = Solution()

for values in test_cases:
    linked_list = create_linked_list(values)
    new_linked_list = solution.oddEvenList(linked_list)
    result_list = linked_list_to_list(new_linked_list)
    print("Original:", values)
    print("Reordered:", result_list)
    print()
