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
var minDistance = function(word1, word2) {
    const m = word1.length;
    const n = word2.length;

    // Create a 2D DP table
    const dp = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));

    // Initialize the DP table
    for (let i = 0; i <= m; i++) {
        dp[i][0] = i; // Insert i characters from word1
    }
    for (let j = 0; j <= n; j++) {
        dp[0][j] = j; // Delete j characters from word1
    }

    // Fill in the DP table
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (word1[i - 1] === word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]); // Choose minimum of insert, delete, or replace
            }
        }
    }

    return dp[m][n];
};

// Test cases
const word1Array = ["horse", "intention", "abc", "", "abcde"];
const word2Array = ["ros", "execution", "", "abc", "bcdea"];
const expectedResults = [3, 5, 3, 3, 2];

for (let i = 0; i < word1Array.length; i++) {
    const word1 = word1Array[i];
    const word2 = word2Array[i];
    const expectedResult = expectedResults[i];

    const result = minDistance(word1, word2);

    console.log("Word1:", word1);
    console.log("Word2:", word2);
    console.log("Expected Result:", expectedResult);
    console.log("Actual Result:", result);
    console.log();

    if (result === expectedResult) {
        console.log("Test case passed!\n");
    } else {
        console.log("Test case failed!\n");
    }
}
