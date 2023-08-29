''' 
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.


'''




class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = set("aeiouAEIOU")
        s = list(s)  # Convert the string to a list of characters
        left, right = 0, len(s) - 1
        
        while left < right:
            if s[left] in vowels and s[right] in vowels:
                # Swap the vowels
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1
            elif s[left] in vowels:
                right -= 1
            else:
                left += 1
        
        return ''.join(s)  # Convert the list back to a string






# Test cases

solution = Solution()
print(solution.reverseVowels("hello"))  # Output: "holle"
print(solution.reverseVowels("leetcode"))  # Output: "leotcede"
