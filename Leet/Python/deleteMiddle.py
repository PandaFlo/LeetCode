'''You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:

Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 


Example 2:

Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.


Example 3:

Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105

'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Solution class
class Solution(object):
    def deleteMiddle(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head or not head.next:
            return None  # No middle node to delete for lists with 0 or 1 nodes
        
        slow = head
        fast = head
        prev = None
        
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        
        if prev:
            prev.next = slow.next  # Delete the middle node
        else:
            head = head.next  # Delete the first node (middle for list of size 2)
        
        return head

# Helper function to print the linked list
def print_list(head):
    current = head
    while current:
        print(current.val, end=" ")
        current = current.next
    print()

# Test cases
if __name__ == "__main__":
    solution = Solution()

    # Example 1
    example1 = ListNode(1, ListNode(3, ListNode(4, ListNode(7, ListNode(1, ListNode(2, ListNode(6)))))))

    print("Example 1 Before:", end=" ")
    print_list(example1)
    
    example1 = solution.deleteMiddle(example1)
    
    print("Example 1 After:", end=" ")
    print_list(example1)

    # Example 2
    example2 = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))

    print("Example 2 Before:", end=" ")
    print_list(example2)
    
    example2 = solution.deleteMiddle(example2)
    
    print("Example 2 After:", end=" ")
    print_list(example2)

    # Example 3
    example3 = ListNode(2, ListNode(1))

    print("Example 3 Before:", end=" ")
    print_list(example3)
    
    example3 = solution.deleteMiddle(example3)
    
    print("Example 3 After:", end=" ")
    print_list(example3)
