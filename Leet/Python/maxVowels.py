'''Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length'''


class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        vowels = 'aeiou'
        def getNumOfVowels(subS):
            return len([char for char in subS if char in vowels])
        cursum = getNumOfVowels(s[: k])
        maxVal = cursum
        for i in range(k, len(s)):
            if s[i] in vowels:
                cursum+=1
            if s[i-k] in vowels:
                cursum-=1
            if maxVal < cursum:
                maxVal = cursum
        return maxVal


# Create an instance of the Solution class
solution = Solution()
print(solution.maxVowels("abciiidef", 3))   # Output: 3
print(solution.maxVowels("aeiou", 2))       # Output: 2
print(solution.maxVowels("leetcode", 3))   # Output: 2