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


import java.util.ArrayList;
import java.util.List;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public int pairSum(ListNode head) {
        List<Integer> values = new ArrayList<>();  // Store the values of the linked list
        
        // Step 1: Traverse the linked list and store values
        ListNode current = head;
        while (current != null) {
            values.add(current.val);
            current = current.next;
        }
        
        int left = 0, right = values.size() - 1;  // Initialize pointers
        int maxTwinSum = 0;  // Initialize maximum twin sum
        
        // Step 3-5: Find maximum twin sum
        while (left < right) {
            int twinSum = values.get(left) + values.get(right);
            maxTwinSum = Math.max(maxTwinSum, twinSum);
            left++;
            right--;
        }
        
        // Step 6: Return the maximum twin sum
        return maxTwinSum;
    }
}

public class pairSum {
    public static void main(String[] args) {
        // Test cases
        ListNode test1 = new ListNode(5, new ListNode(4, new ListNode(2, new ListNode(1))));  // Expected output: 6
        ListNode test2 = new ListNode(4, new ListNode(2, new ListNode(2, new ListNode(3))));  // Expected output: 7
        ListNode test3 = new ListNode(1, new ListNode(100000));  // Expected output: 100001
        ListNode test4 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));  // Expected output: 7
        ListNode test5 = new ListNode(10, new ListNode(20, new ListNode(30, new ListNode(40, new ListNode(50)))));  // Expected output: 60

        Solution solution = new Solution();

        // Test 1
        int result1 = solution.pairSum(test1);
        System.out.println("Test 1 Result: " + result1);

        // Test 2
        int result2 = solution.pairSum(test2);
        System.out.println("Test 2 Result: " + result2);

        // Test 3
        int result3 = solution.pairSum(test3);
        System.out.println("Test 3 Result: " + result3);

        // Test 4
        int result4 = solution.pairSum(test4);
        System.out.println("Test 4 Result: " + result4);

        // Test 5
        int result5 = solution.pairSum(test5);
        System.out.println("Test 5 Result: " + result5);
    }
}
