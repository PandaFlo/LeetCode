/* You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

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

*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr; // No middle node to delete for lists with 0 or 1 nodes
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (prev) {
            prev->next = slow->next; // Delete the middle node
        } else {
            head = head->next; // Delete the first node (middle for list of size 2)
        }
        
        delete slow;
        
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Example 1
    ListNode* example1 = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(7, new ListNode(1, new ListNode(2, new ListNode(6)))))));

    std::cout << "Example 1 Before: ";
    printList(example1);
    
    example1 = solution.deleteMiddle(example1);
    
    std::cout << "Example 1 After: ";
    printList(example1);

    // Example 2
    ListNode* example2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    std::cout << "Example 2 Before: ";
    printList(example2);
    
    example2 = solution.deleteMiddle(example2);
    
    std::cout << "Example 2 After: ";
    printList(example2);

    // Example 3
    ListNode* example3 = new ListNode(2, new ListNode(1));

    std::cout << "Example 3 Before: ";
    printList(example3);
    
    example3 = solution.deleteMiddle(example3);
    
    std::cout << "Example 3 After: ";
    printList(example3);

    return 0;
}
