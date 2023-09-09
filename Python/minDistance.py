'''Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

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
'''


class Solution(object):
    def minDistance(self, word1, word2):
        m = len(word1)
        n = len(word2)

        # Create a 2D DP table
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # Initialize the DP table
        for i in range(m + 1):
            dp[i][0] = i  # Insert i characters from word1
        for j in range(n + 1):
            dp[0][j] = j  # Delete j characters from word1

        # Fill in the DP table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]  # No operation needed
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])  # Choose minimum of insert, delete, or replace

        return dp[m][n]

def tester():
    solution = Solution()

    # Test cases
    word1_array = ["horse", "intention", "abc", "", "abcde"]
    word2_array = ["ros", "execution", "", "abc", "bcdea"]
    expected_results = [3, 5, 3, 3, 2]

    for i in range(len(word1_array)):
        word1 = word1_array[i]
        word2 = word2_array[i]
        expected_result = expected_results[i]

        result = solution.minDistance(word1, word2)

        print("Word1:", word1)
        print("Word2:", word2)
        print("Expected Result:", expected_result)
        print("Actual Result:", result)
        print()

        if result == expected_result:
            print("Test case passed!\n")
        else:
            print("Test case failed!\n")

tester()
