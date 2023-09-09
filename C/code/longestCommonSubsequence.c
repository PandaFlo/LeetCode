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
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1);
    int n = strlen(text2);

    // Create a 2D array to store the lengths of longest common subsequences.
    int dp[m + 1][n + 1];

    // Initialize the first row and first column to 0.
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Calculate the lengths of longest common subsequences using dynamic programming.
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The value in dp[m][n] represents the length of the longest common subsequence.
    return dp[m][n];
}

int main() {
    char text1[] = "abcde";
    char text2[] = "ace";
    int result = longestCommonSubsequence(text1, text2);
    printf("Longest Common Subsequence: %d\n", result);

    char text3[] = "abc";
    char text4[] = "abc";
    result = longestCommonSubsequence(text3, text4);
    printf("Longest Common Subsequence: %d\n", result);

    char text5[] = "abc";
    char text6[] = "def";
    result = longestCommonSubsequence(text5, text6);
    printf("Longest Common Subsequence: %d\n", result);

    return 0;
}
