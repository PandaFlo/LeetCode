/* Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
 */


 class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        // Create a 2D DP table
        int[][] dp = new int[m + 1][n + 1];
        
        // Initialize the DP table
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = j; // Insert j characters from word2
                } else if (j == 0) {
                    dp[i][j] = i; // Delete i characters from word1
                } else if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1]; // No operation needed
                } else {
                    // Choose the minimum of insert, delete, or replace operation
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        
        return dp[m][n];
    }
}

public class minDistance {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test cases
        String[] word1Array = {"horse", "intention", "abc", ""};
        String[] word2Array = {"ros", "execution", "", "abc"};
        int[] expectedResults = {3, 5, 3, 3, 4};

        for (int i = 0; i < word1Array.length; i++) {
            String word1 = word1Array[i];
            String word2 = word2Array[i];
            int expectedResult = expectedResults[i];

            int result = solution.minDistance(word1, word2);

            System.out.println("Word1: " + word1);
            System.out.println("Word2: " + word2);
            System.out.println("Expected Result: " + expectedResult);
            System.out.println("Actual Result: " + result);
            System.out.println();

            if (result == expectedResult) {
                System.out.println("Test case passed!" + System.lineSeparator());
            } else {
                System.out.println("Test case failed!" + System.lineSeparator());
            }
        }
    }
}

