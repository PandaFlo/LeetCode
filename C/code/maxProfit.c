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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize, int fee) {
    if (pricesSize <= 1) {
        return 0;
    }
    
    int* hold = (int*)malloc(pricesSize * sizeof(int));
    int* notHold = (int*)malloc(pricesSize * sizeof(int));
    
    hold[0] = -prices[0];
    notHold[0] = 0;
    
    for (int i = 1; i < pricesSize; i++) {
        hold[i] = fmax(hold[i - 1], notHold[i - 1] - prices[i]);
        notHold[i] = fmax(notHold[i - 1], hold[i - 1] + prices[i] - fee);
    }
    
    int maxProfit = notHold[pricesSize - 1];
    
    free(hold);
    free(notHold);
    
    return maxProfit;
}

int main() {
    int prices1[] = {1, 3, 2, 8, 4, 9};
    int fee1 = 2;
    int result1 = maxProfit(prices1, 6, fee1);
    printf("Expected Result 1: 8\n");
    printf("Actual Result 1: %d\n\n", result1);
    
    int prices2[] = {1, 3, 7, 5, 10, 3};
    int fee2 = 3;
    int result2 = maxProfit(prices2, 6, fee2);
    printf("Expected Result 2: 6\n");
    printf("Actual Result 2: %d\n\n", result2);
    
    return 0;
}



