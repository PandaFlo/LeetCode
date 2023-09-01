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

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val === undefined ? 0 : val)
 *     this.next = (next === undefined ? null : next)
 * }
 */



// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var oddEvenList = function(head) {
    if (!head || !head.next) {
        return head;
    }
    
    let oddHead = oddCurr = head;
    let evenHead = evenCurr = head.next;
    
    let curr = head.next.next;
    let index = 3;  // Start with the third node (1-indexed)
    
    while (curr) {
        if (index % 2 === 1) {
            oddCurr.next = curr;
            oddCurr = oddCurr.next;
        } else {
            evenCurr.next = curr;
            evenCurr = evenCurr.next;
        }
        curr = curr.next;
        index++;
    }
    
    oddCurr.next = evenHead;
    evenCurr.next = null;  // Set the next of the last even node to null
    
    return oddHead;
};

// Helper function to create a linked list from an array of values
function createLinkedList(values) {
    let dummy = new ListNode();
    let curr = dummy;
    for (let val of values) {
        curr.next = new ListNode(val);
        curr = curr.next;
    }
    return dummy.next;
}

// Helper function to convert linked list to array for comparison
function linkedListToArray(head) {
    let result = [];
    let curr = head;
    while (curr) {
        result.push(curr.val);
        curr = curr.next;
    }
    return result;
}

// Test cases
const testCases = [
    [1, 2, 3, 4, 5],
    [2, 1, 3, 5, 6, 4, 7]
];

for (let values of testCases) {
    const linkedList = createLinkedList(values);
    const newLinkedList = oddEvenList(linkedList);
    const resultArray = linkedListToArray(newLinkedList);
    console.log("Original:", values);
    console.log("Reordered:", resultArray);
    console.log();
}
