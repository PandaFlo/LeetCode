/* You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
 */
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        
        // Create an array to store the minimum cost to reach each step.
        int[] minCost = new int[n];
        
        // Initialize the minimum cost for the first two steps.
        minCost[0] = cost[0];
        minCost[1] = cost[1];
        
        // Iterate through the remaining steps, calculating the minimum cost.
        for (int i = 2; i < n; i++) {
            minCost[i] = cost[i] + Math.min(minCost[i - 1], minCost[i - 2]);
        }
        
        // Return the minimum cost of reaching the last step (top of the floor).
        return Math.min(minCost[n - 1], minCost[n - 2]);
    }
}


public class minCostClimbingStairs {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test cases
        int[] testCases1 = {10, 15, 20};
        int[] testCases2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

        int result1 = solution.minCostClimbingStairs(testCases1);
        int result2 = solution.minCostClimbingStairs(testCases2);

        System.out.println("Minimum cost for test case 1: " + result1);
        System.out.println("Minimum cost for test case 2: " + result2);
    }
}
