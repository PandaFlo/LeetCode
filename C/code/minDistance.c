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


#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j; // Insert j characters from word2
            } else if (j == 0) {
                dp[i][j] = i; // Delete i characters from word1
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])); // Choose minimum of insert, delete, or replace
            }
        }
    }

    return dp[m][n];
}

void tester() {
    // Test cases
    char* word1Array[] = {"horse", "intention", "abc", ""};
    char* word2Array[] = {"ros", "execution", "", "abc"};
    int expectedResults[] = {3, 5, 3, 3, 4};
    int numTestCases = sizeof(word1Array) / sizeof(word1Array[0]);

    for (int i = 0; i < numTestCases; i++) {
        char* word1 = word1Array[i];
        char* word2 = word2Array[i];
        int expectedResult = expectedResults[i];

        int result = minDistance(word1, word2);

        printf("Word1: %s\n", word1);
        printf("Word2: %s\n", word2);
        printf("Expected Result: %d\n", expectedResult);
        printf("Actual Result: %d\n", result);
        printf("\n");

        if (result == expectedResult) {
            printf("Test case passed!\n\n");
        } else {
            printf("Test case failed!\n\n");
        }
    }
}

int main() {
    tester();
    return 0;
}
