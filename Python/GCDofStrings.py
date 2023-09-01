'''
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
'''

class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        # If str1 + str2 is equal to str2 + str1, then GCD exists
        if str1 + str2 == str2 + str1:
            # Find the GCD using the built-in GCD function
            # This function returns the greatest common divisor of two integers
            def gcd(a, b):
                while b:
                    a, b = b, a % b
                return a
            
            # Return the GCD string from the beginning of str1 up to the calculated GCD length
            return str1[:gcd(len(str1), len(str2))]
        else:
            return ""



# Test cases
solution = Solution()
str1 = "ABCABC"
str2 = "ABC"
result = solution.gcdOfStrings(str1, str2)
print(result)  # Output: "ABC"
