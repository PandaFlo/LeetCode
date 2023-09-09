/* You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
 */
import java.util.Arrays;



 class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        if (n <= 1) {
            return 0;
        }
        
        int[] hold = new int[n];
        int[] notHold = new int[n];
        
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            hold[i] = Math.max(hold[i - 1], notHold[i - 1] - prices[i]);
            notHold[i] = Math.max(notHold[i - 1], hold[i - 1] + prices[i] - fee);
        }
        
        return notHold[n - 1];
    }
}

public class maxProfit {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test cases
        int[][] testCases = {
            {1, 3, 2, 8, 4, 9}, // Prices
            {2},                // Fee
            {1, 3, 7, 5, 10, 3},// Prices
            {3}                 // Fee
        };

        int result = solution.maxProfit(testCases[0], testCases[1][0]);
        System.out.println("Prices: " + Arrays.toString(testCases[0]));
        System.out.println("Fee: " + testCases[1][0]);
        System.out.println("Expected Result: 8");
        System.out.println("Actual Result: " + result);
        System.out.println();

        result = solution.maxProfit(testCases[2], testCases[3][0]);
        System.out.println("Prices: " + Arrays.toString(testCases[2]));
        System.out.println("Fee: " + testCases[3][0]);
        System.out.println("Expected Result: 6");
        System.out.println("Actual Result: " + result);
        System.out.println();
    }
}

