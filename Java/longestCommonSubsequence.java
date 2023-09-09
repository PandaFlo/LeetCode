/* Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
 */


 class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        
        // Create a 2D array to store the lengths of longest common subsequences.
        int[][] dp = new int[m + 1][n + 1];
        
        // Calculate the lengths of longest common subsequences using dynamic programming.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The value in dp[m][n] represents the length of the longest common subsequence.
        return dp[m][n];
    }
}


public class longestCommonSubsequence {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test cases
        String[] text1Array = {"abcde", "abc", "abc"};
        String[] text2Array = {"ace", "abc", "def"};
        int[] expectedResults = {3, 3, 0};

        for (int i = 0; i < text1Array.length; i++) {
            String text1 = text1Array[i];
            String text2 = text2Array[i];
            int expectedResult = expectedResults[i];
            int result = solution.longestCommonSubsequence(text1, text2);

            System.out.println("Text1: " + text1);
            System.out.println("Text2: " + text2);
            System.out.println("Expected Result: " + expectedResult);
            System.out.println("Actual Result: " + result);
            System.out.println();

            if (result == expectedResult) {
                System.out.println("Test case passed!\n");
            } else {
                System.out.println("Test case failed!\n");
            }
        }
    }
}
