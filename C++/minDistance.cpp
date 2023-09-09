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

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // Create a 2D DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize the DP table
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i; // Insert i characters from word1
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j; // Delete j characters from word1
        }

        // Fill in the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // No operation needed
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])); // Choose minimum of insert, delete, or replace
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;

    // Test cases
    string word1Array[] = {"horse", "intention", "abc", "", "abcde"};
    string word2Array[] = {"ros", "execution", "", "abc", "bcdea"};
    int expectedResults[] = {3, 5, 3, 3, 2};

    for (int i = 0; i < sizeof(word1Array) / sizeof(word1Array[0]); i++) {
        string word1 = word1Array[i];
        string word2 = word2Array[i];
        int expectedResult = expectedResults[i];

        int result = solution.minDistance(word1, word2);

        cout << "Word1: " << word1 << endl;
        cout << "Word2: " << word2 << endl;
        cout << "Expected Result: " << expectedResult << endl;
        cout << "Actual Result: " << result << endl << endl;

        if (result == expectedResult) {
            cout << "Test case passed!" << endl << endl;
        } else {
            cout << "Test case failed!" << endl << endl;
        }
    }

    return 0;
}

