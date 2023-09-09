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


#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;  // Store the values of the linked list

        // Step 1: Traverse the linked list and store values
        ListNode* current = head;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }

        int left = 0, right = values.size() - 1;  // Initialize pointers
        int maxTwinSum = 0;  // Initialize maximum twin sum

        // Step 3-5: Find maximum twin sum
        while (left < right) {
            int twinSum = values[left] + values[right];
            maxTwinSum = max(maxTwinSum, twinSum);
            left++;
            right--;
        }

        // Step 6: Return the maximum twin sum
        return maxTwinSum;
    }
};

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Test cases
    vector<int> test1 = {5, 4, 2, 1};  // Expected output: 6
    vector<int> test2 = {4, 2, 2, 3};  // Expected output: 7
    vector<int> test3 = {1, 100000};   // Expected output: 100001
    vector<int> test4 = {1, 2, 3, 4};  // Expected output: 7
    vector<int> test5 = {10, 20, 30, 40, 50};  // Expected output: 60

    Solution solution;

    // Test 1
    ListNode* head1 = createLinkedList(test1);
    int result1 = solution.pairSum(head1);
    cout << "Test 1 Result: " << result1 << endl;
    printLinkedList(head1);

    // Test 2
    ListNode* head2 = createLinkedList(test2);
    int result2 = solution.pairSum(head2);
    cout << "Test 2 Result: " << result2 << endl;
    printLinkedList(head2);

    // Test 3
    ListNode* head3 = createLinkedList(test3);
    int result3 = solution.pairSum(head3);
    cout << "Test 3 Result: " << result3 << endl;
    printLinkedList(head3);

    // Test 4
    ListNode* head4 = createLinkedList(test4);
    int result4 = solution.pairSum(head4);
    cout << "Test 4 Result: " << result4 << endl;
    printLinkedList(head4);

    // Test 5
    ListNode* head5 = createLinkedList(test5);
    int result5 = solution.pairSum(head5);
    cout << "Test 5 Result: " << result5 << endl;
    printLinkedList(head5);

    // Clean up memory (deallocate linked list nodes)
    ListNode* current = head1;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    current = head2;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    current = head3;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    current = head4;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    current = head5;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
