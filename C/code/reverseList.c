/* Given the head of a singly linked list, reverse the list, and return the reversed list.

 

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
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?�>��� */



  //Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 

// Iterative approach

#include <stdio.h>
#include <stdlib.h>


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    
    while (current != NULL) {
        struct ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    
    return prev;
}

// Recursive approach
struct ListNode* reverseListRecursive(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

// Main function (example usage)
int main() {
    // Create a linked list for testing
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 1; i <= 5; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = i;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Reverse the linked list using the iterative approach
    struct ListNode* reversedIterative = reverseList(head);
    
    // Print the reversed linked list
    while (reversedIterative != NULL) {
        printf("%d ", reversedIterative->val);
        reversedIterative = reversedIterative->next;
    }
    
    printf("\n");
    
    // Re-create the linked list for testing
    head = NULL;
    tail = NULL;
    for (int i = 1; i <= 5; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = i;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Reverse the linked list using the recursive approach
    struct ListNode* reversedRecursive = reverseListRecursive(head);
    
    // Print the reversed linked list
    while (reversedRecursive != NULL) {
        printf("%d ", reversedRecursive->val);
        reversedRecursive = reversedRecursive->next;
    }
    
    return 0;
}
