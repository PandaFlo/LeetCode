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


function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

var deleteMiddle = function(head) {
    if (!head || !head.next) {
        return null; // No middle node to delete for lists with 0 or 1 nodes
    }
    
    let length = 0;
    let current = head;
    while (current) {
        length++;
        current = current.next;
    }
    
    const middleIndex = Math.floor(length / 2);
    
    if (middleIndex === 0) {
        return head.next; // Delete the first node (middle for list of size 2)
    }
    
    current = head;
    for (let i = 0; i < middleIndex - 1; i++) {
        current = current.next;
    }
    
    current.next = current.next.next; // Delete the middle node
    
    return head;
};

// Example 1
const example1 = new ListNode(1,
    new ListNode(3,
        new ListNode(4,
            new ListNode(7,
                new ListNode(1,
                    new ListNode(2,
                        new ListNode(6)
                    )
                )
            )
        )
    )
);

console.log("Example 1 Before:");
let current = example1;
while (current) {
    console.log(current.val);
    current = current.next;
}

deleteMiddle(example1);

console.log("Example 1 After:");
current = example1;
while (current) {
    console.log(current.val);
    current = current.next;
}

// Example 2
const example2 = new ListNode(1,
    new ListNode(2,
        new ListNode(3,
            new ListNode(4)
        )
    )
);

console.log("Example 2 Before:");
current = example2;
while (current) {
    console.log(current.val);
    current = current.next;
}

deleteMiddle(example2);

console.log("Example 2 After:");
current = example2;
while (current) {
    console.log(current.val);
    current = current.next;
}

// Example 3
const example3 = new ListNode(2, new ListNode(1));

console.log("Example 3 Before:");
current = example3;
while (current) {
    console.log(current.val);
    current = current.next;
}

deleteMiddle(example3);

console.log("Example 3 After:");
current = example3;
while (current) {
    console.log(current.val);
    current = current.next;
}

