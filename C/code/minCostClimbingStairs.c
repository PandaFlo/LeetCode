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

#include <stdio.h>
#include <stdlib.h>

int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize <= 1) {
        return 0; // If there are 0 or 1 steps, the cost is 0.
    }

    // Create an array to store the minimum cost to reach each step.
    int* minCost = (int*)malloc(costSize * sizeof(int));
    minCost[0] = cost[0];
    minCost[1] = cost[1];

    // Iterate through the remaining steps, calculating the minimum cost.
    for (int i = 2; i < costSize; i++) {
        minCost[i] = cost[i] + fmin(minCost[i - 1], minCost[i - 2]);
    }

    // The minimum cost to reach the top floor is either the cost of the last step or the second-to-last step.
    int result = fmin(minCost[costSize - 1], minCost[costSize - 2]);

    free(minCost); // Free the dynamically allocated memory.

    return result;
}


int minCostClimbingStairs(int* cost, int costSize);

void tester() {
    int testCases1[] = {10, 15, 20};
    int testCases2[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int result1, result2;

    result1 = minCostClimbingStairs(testCases1, sizeof(testCases1) / sizeof(testCases1[0]));
    result2 = minCostClimbingStairs(testCases2, sizeof(testCases2) / sizeof(testCases2[0]));

    printf("Minimum cost for test case 1: %d\n", result1);
    printf("Minimum cost for test case 2: %d\n", result2);
}

int main() {
    tester();
    return 0;
}
