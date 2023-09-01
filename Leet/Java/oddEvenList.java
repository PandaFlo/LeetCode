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

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

 class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
   public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode oddHead = head;
        ListNode evenHead = head.next;
        ListNode oddCurr = oddHead;
        ListNode evenCurr = evenHead;
        
        ListNode curr = head.next.next;
        int index = 3;  // Start with the third node (1-indexed)
        
        while (curr != null) {
            if (index % 2 == 1) {
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
    }
}

public class oddEvenList {
    // Helper function to create a linked list from an array of values
    public static ListNode createLinkedList(int[] values) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        for (int val : values) {
            curr.next = new ListNode(val);
            curr = curr.next;
        }
        return dummy.next;
    }

    // Helper function to convert linked list to array for comparison
    public static int[] linkedListToArray(ListNode head) {
        List<Integer> result = new ArrayList<>();
        ListNode curr = head;
        while (curr != null) {
            result.add(curr.val);
            curr = curr.next;
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Test cases
        int[][] testCases = {
            {1, 2, 3, 4, 5},
            {2, 1, 3, 5, 6, 4, 7}
        };

        for (int[] values : testCases) {
            ListNode linkedList = createLinkedList(values);
            ListNode newLinkedList = solution.oddEvenList(linkedList);
            int[] resultArray = linkedListToArray(newLinkedList);
            System.out.println("Original: " + Arrays.toString(values));
            System.out.println("Reordered: " + Arrays.toString(resultArray));
            System.out.println();
        }
    }
}
