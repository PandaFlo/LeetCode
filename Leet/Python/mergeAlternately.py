''' 
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100


'''




class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        # Convert input strings into lists of characters
        lst1 = list(word1)
        lst2 = list(word2)
        
        # Merge characters from both lists alternatively, up to the length of the shorter string
        same_length = ''.join(map(lambda x, y: (x or '') + (y or ''), lst1, lst2))
        
        # Create a list of extra characters from the longer string
        extra_list = lst1[len(lst2):] + lst2[len(lst1):]
        
        # Join the extra characters into a string
        extra_str = ''.join(extra_list)
        
        # Concatenate the merged characters and extra characters to get the final merged string
        return same_length + extra_str




# Test cases
solution = Solution()

word1_1, word2_1 = "abc", "pqr"
output_1 = solution.mergeAlternately(word1_1, word2_1)
print(output_1)  # Output: "apbqcr"

word1_2, word2_2 = "ab", "pqrs"
output_2 = solution.mergeAlternately(word1_2, word2_2)
print(output_2)  # Output: "apbqrs"

word1_3, word2_3 = "abcd", "pq"
output_3 = solution.mergeAlternately(word1_3, word2_3)
print(output_3)  # Output: "apbqcd"