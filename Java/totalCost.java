/* You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.

 

Example 1:

Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
The total hiring cost is 11.
Example 2:

Input: costs = [1,2,4,1], k = 3, candidates = 3
Output: 4
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [1,2,4,1]. The lowest cost is 1, and we break the tie by the smallest index, which is 0. The total cost = 0 + 1 = 1. Notice that workers with index 1 and 2 are common in the first and last 3 workers.
- In the second hiring round we choose the worker from [2,4,1]. The lowest cost is 1 (index 2). The total cost = 1 + 1 = 2.
- In the third hiring round there are less than three candidates. We choose the worker from the remaining workers [2,4]. The lowest cost is 2 (index 0). The total cost = 2 + 2 = 4.
The total hiring cost is 4.
 

Constraints:

1 <= costs.length <= 105 
1 <= costs[i] <= 105
1 <= k, candidates <= costs.length
 */



import java.util.PriorityQueue;
 
 
 class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        long sum = 0;
        int len1 = 0, len2 = 0;
        PriorityQueue<Integer> headQueue = new PriorityQueue<>();
        PriorityQueue<Integer> tailQueue = new PriorityQueue<>();

        int head = 0;
        int tail = costs.length - 1;

        for (int i = 0; i < candidates; i++) {
            if (head > tail) {
                break;
            }
            push(headQueue, costs[head++], len1);

            if (head > tail) {
                break;
            }
            push(tailQueue, costs[tail--], len2);
        }

        for (int i = 0; i < k; i++) {
            Integer ret1 = pop(headQueue, len1);
            Integer ret2 = pop(tailQueue, len2);

            if (ret1 == null) {
                sum += ret2;
                if (head <= tail) {
                    push(tailQueue, costs[tail--], len2);
                }
                continue;
            }

            if (ret2 == null) {
                sum += ret1;
                if (head <= tail) {
                    push(headQueue, costs[head++], len1);
                }
                continue;
            }

            if (ret1 <= ret2) {
                sum += ret1;
                if (head <= tail) {
                    push(headQueue, costs[head++], len1);
                }
                push(tailQueue, ret2, len2);
            } else {
                sum += ret2;
                if (head <= tail) {
                    push(tailQueue, costs[tail--], len2);
                }
                push(headQueue, ret1, len1);
            }
        }

        return sum;
    }

    private void push(PriorityQueue<Integer> queue, int value, int len) {
        queue.offer(value);
    }

    private Integer pop(PriorityQueue<Integer> queue, int len) {
        if (queue.isEmpty()) {
            return null;
        }
        return queue.poll();
    }
}


public class totalCost{
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        int[] costs1 = {17, 12, 10, 2, 7, 2, 11, 20, 8};
        int k1 = 3;
        int candidates1 = 4;
        long result1 = solution.totalCost(costs1, k1, candidates1);
        System.out.println("Test Case 1 Result: " + result1);  // Expected Output: 11

        // Test case 2
        int[] costs2 = {1, 2, 4, 1};
        int k2 = 3;
        int candidates2 = 3;
        long result2 = solution.totalCost(costs2, k2, candidates2);
        System.out.println("Test Case 2 Result: " + result2);  // Expected Output: 4

        // Add more test cases as needed

    }
}
