/* There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
 */

class Solution {
    public int uniquePaths(int m, int n) {
        // Create a 2D array to store the number of unique paths.
        int[][] dp = new int[m][n];

        // Initialize the first row and first column to 1 because there's only one way to reach any cell in these rows/columns.
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // Calculate the number of unique paths for each cell using dynamic programming.
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // The value in the bottom-right cell represents the number of unique paths from the top-left to the bottom-right.
        return dp[m - 1][n - 1];
    }
}


public class uniquePaths {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test cases
        int[][] testCases = {
            {3, 7}, // Expected: 28
            {3, 2}, // Expected: 3
            // Add more test cases as needed
        };

        for (int[] testCase : testCases) {
            int m = testCase[0];
            int n = testCase[1];
            int result = solution.uniquePaths(m, n);

            System.out.println("For m=" + m + " and n=" + n + ", got: " + result);
        }
    }
}
