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


#include <iostream>
#include <vector>

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        } 
        ListNode *odd = head, *even = head->next, *evenStart = even, * oddStart = head;
        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }
        odd->next = evenStart;
        return oddStart;
    }
};

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    for (int val : values) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to convert linked list to vector for comparison
std::vector<int> linkedListToVector(ListNode* head) {
    std::vector<int> result;
    ListNode* curr = head;
    while (curr) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
}

int main() {
    Solution solution;
    
    // Test cases
    std::vector<std::vector<int>> testCases = {
        {1, 2, 3, 4, 5},
        {2, 1, 3, 5, 6, 4, 7}
    };

    for (const std::vector<int>& values : testCases) {
        ListNode* linkedList = createLinkedList(values);
        ListNode* newLinkedList = solution.oddEvenList(linkedList);
        std::vector<int> resultVector = linkedListToVector(newLinkedList);
        
        std::cout << "Original: ";
        for (int val : values) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Reordered: ";
        for (int val : resultVector) {
            std::cout << val << " ";
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}
