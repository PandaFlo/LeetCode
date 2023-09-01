/* Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

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
 */


#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    
    struct ListNode* oddHead = head;
    struct ListNode* evenHead = head->next;
    struct ListNode* oddCurr = oddHead;
    struct ListNode* evenCurr = evenHead;
    
    struct ListNode* curr = head->next->next;
    int index = 3;  // Start with the third node (1-indexed)
    
    while (curr) {
        if (index % 2 == 1) {
            oddCurr->next = curr;
            oddCurr = oddCurr->next;
        } else {
            evenCurr->next = curr;
            evenCurr = evenCurr->next;
        }
        curr = curr->next;
        index++;
    }
    
    oddCurr->next = evenHead;
    evenCurr->next = NULL;  // Set the next of the last even node to NULL
    
    return oddHead;
}
// Helper function to create a linked list from an array of values
struct ListNode* createLinkedList(int values[], int length) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curr = dummy;
    for (int i = 0; i < length; ++i) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = values[i];
        curr->next = NULL;
    }
    return dummy->next;
}

// Helper function to convert linked list to array for comparison
void linkedListToArray(struct ListNode* head, int array[], int length) {
    struct ListNode* curr = head;
    for (int i = 0; i < length; ++i) {
        array[i] = curr->val;
        curr = curr->next;
    }
}

int main() {
    // Test cases
    int test_case_1[] = {1, 2, 3, 4, 5};
    int test_case_2[] = {2, 1, 3, 5, 6, 4, 7};
    
    int length_1 = sizeof(test_case_1) / sizeof(test_case_1[0]);
    int length_2 = sizeof(test_case_2) / sizeof(test_case_2[0]);
    
    struct ListNode* linked_list_1 = createLinkedList(test_case_1, length_1);
    struct ListNode* linked_list_2 = createLinkedList(test_case_2, length_2);
    
    struct ListNode* new_linked_list_1 = oddEvenList(linked_list_1);
    struct ListNode* new_linked_list_2 = oddEvenList(linked_list_2);
    
    int result_array_1[length_1];
    int result_array_2[length_2];
    
    linkedListToArray(new_linked_list_1, result_array_1, length_1);
    linkedListToArray(new_linked_list_2, result_array_2, length_2);
    
    printf("Original Test Case 1: ");
    for (int i = 0; i < length_1; ++i) {
        printf("%d ", test_case_1[i]);
    }
    printf("\nReordered Test Case 1: ");
    for (int i = 0; i < length_1; ++i) {
        printf("%d ", result_array_1[i]);
    }
    printf("\n\n");
    
    printf("Original Test Case 2: ");
    for (int i = 0; i < length_2; ++i) {
        printf("%d ", test_case_2[i]);
    }
    printf("\nReordered Test Case 2: ");
    for (int i = 0; i < length_2; ++i) {
        printf("%d ", result_array_2[i]);
    }
    printf("\n\n");
    
    // Clean up memory
    free(new_linked_list_1);
    free(new_linked_list_2);
    
    return 0;
}
