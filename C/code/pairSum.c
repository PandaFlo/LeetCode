/* In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

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
 */


#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

int pairSum(struct ListNode* head) {
    int values[100000];  // Assuming a maximum of 100,000 elements (adjust as needed)
    int length = 0;

    // Step 1: Traverse the linked list and store values
    struct ListNode* current = head;
    while (current != NULL) {
        values[length] = current->val;
        length++;
        current = current->next;
    }

    int left = 0, right = length - 1;  // Initialize pointers
    int maxTwinSum = 0;  // Initialize maximum twin sum

    // Step 3-5: Find maximum twin sum
    while (left < right) {
        int twinSum = values[left] + values[right];
        maxTwinSum = (twinSum > maxTwinSum) ? twinSum : maxTwinSum;
        left++;
        right--;
    }

    // Step 6: Return the maximum twin sum
    return maxTwinSum;
}

// Helper function to create a linked list from an array
struct ListNode* createLinkedList(int arr[], int n) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Helper function to print the linked list
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Test cases
    int test1[] = {5, 4, 2, 1};
    int test2[] = {4, 2, 2, 3};
    int test3[] = {1, 100000};
    int test4[] = {1, 2, 3, 4};
    int test5[] = {10, 20, 30, 40, 50};

    struct ListNode* head1 = createLinkedList(test1, sizeof(test1) / sizeof(test1[0]));
    struct ListNode* head2 = createLinkedList(test2, sizeof(test2) / sizeof(test2[0]));
    struct ListNode* head3 = createLinkedList(test3, sizeof(test3) / sizeof(test3[0]));
    struct ListNode* head4 = createLinkedList(test4, sizeof(test4) / sizeof(test4[0]));
    struct ListNode* head5 = createLinkedList(test5, sizeof(test5) / sizeof(test5[0]));

    printf("Test 1: ");
    printLinkedList(head1);
    printf("Maximum Twin Sum: %d\n\n", pairSum(head1));

    printf("Test 2: ");
    printLinkedList(head2);
    printf("Maximum Twin Sum: %d\n\n", pairSum(head2));

    printf("Test 3: ");
    printLinkedList(head3);
    printf("Maximum Twin Sum: %d\n\n", pairSum(head3));

    printf("Test 4: ");
    printLinkedList(head4);
    printf("Maximum Twin Sum: %d\n\n", pairSum(head4));

    printf("Test 5: ");
    printLinkedList(head5);
    printf("Maximum Twin Sum: %d\n\n", pairSum(head5));

    return 0;
}
