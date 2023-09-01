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


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    if (!head || !head->next) {
        return NULL; // No middle node to delete for lists with 0 or 1 nodes
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;
    
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
    
    free(slow);
    
    return head;
}

// Helper function to create a linked list node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Test case 1
    struct ListNode* example1 = createNode(1);
    example1->next = createNode(3);
    example1->next->next = createNode(4);
    example1->next->next->next = createNode(7);
    example1->next->next->next->next = createNode(1);
    example1->next->next->next->next->next = createNode(2);
    example1->next->next->next->next->next->next = createNode(6);

    printf("Example 1 Before: ");
    printList(example1);
    
    example1 = deleteMiddle(example1);
    
    printf("Example 1 After: ");
    printList(example1);
    
    // Test case 2
    struct ListNode* example2 = createNode(1);
    example2->next = createNode(2);
    example2->next->next = createNode(3);
    example2->next->next->next = createNode(4);

    printf("Example 2 Before: ");
    printList(example2);
    
    example2 = deleteMiddle(example2);
    
    printf("Example 2 After: ");
    printList(example2);
    
    // Test case 3
    struct ListNode* example3 = createNode(2);
    example3->next = createNode(1);

    printf("Example 3 Before: ");
    printList(example3);
    
    example3 = deleteMiddle(example3);
    
    printf("Example 3 After: ");
    printList(example3);

    return 0;
}
