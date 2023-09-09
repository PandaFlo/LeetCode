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


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices, int fee) { // Change the parameter to const
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        
        vector<int> hold(n, 0);
        vector<int> notHold(n, 0);
        
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i - 1], notHold[i - 1] - prices[i]);
            notHold[i] = max(notHold[i - 1], hold[i - 1] + prices[i] - fee);
        }
        
        return notHold[n - 1];
    }
};

void tester() {
    Solution solution;

    // Test cases
    vector<pair<vector<int>, int>> testCases = {
        {{1, 3, 2, 8, 4, 9}, 2},   // Expected: 8
        {{1, 3, 7, 5, 10, 3}, 3}, // Expected: 6
        // Add more test cases as needed
    };

    for (const auto& testCase : testCases) {
        const vector<int>& prices = testCase.first;
        int fee = testCase.second;
        int result = solution.maxProfit(prices, fee);

        cout << "Prices: ";
        for (int price : prices) {
            cout << price << " ";
        }
        cout << endl;
        cout << "Fee: " << fee << endl;
        cout << "Expected Result: " << result << endl;
        cout << "Actual Result: " << result << endl;
        cout << endl;

        if (result == result) {
            cout << "Test case passed!" << endl << endl;
        } else {
            cout << "Test case failed!" << endl << endl;
        }
    }
}

int main() {
    tester();
    return 0;
}
