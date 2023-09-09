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

/**
 * Definition for singly-linked list.
 */
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    let prev = null;
    let current = head;
    
    while (current !== null) {
        let nextNode = current.next;
        current.next = prev;
        prev = current;
        current = nextNode;
    }
    
    return prev;
};

// Helper function to create a linked list from an array
function createLinkedList(arr) {
    let dummy = new ListNode();
    let current = dummy;

    for (let val of arr) {
        current.next = new ListNode(val);
        current = current.next;
    }

    return dummy.next;
}

// Helper function to print a linked list
function printLinkedList(head) {
    let current = head;
    while (current !== null) {
        console.log(current.val + " ");
        current = current.next;
    }
}

// Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
let originalList = createLinkedList([1, 2, 3, 4, 5]);

// Reverse the linked list
let reversedList = reverseList(originalList);

// Print the reversed linked list
printLinkedList(reversedList);
