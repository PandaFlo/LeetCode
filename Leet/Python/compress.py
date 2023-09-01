'''Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 

Constraints:

1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.'''


class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        # Initialize pointers and counters
        read_ptr = 0
        write_ptr = 0
        
        while read_ptr < len(chars):
            # Current character
            char = chars[read_ptr]
            # Count consecutive characters
            count = 0
            
            # Count consecutive characters
            while read_ptr < len(chars) and chars[read_ptr] == char:
                read_ptr += 1
                count += 1
            
            # Write character to output
            chars[write_ptr] = char
            write_ptr += 1
            
            # Write count if count > 1
            if count > 1:
                count_str = str(count)
                for digit in count_str:
                    chars[write_ptr] = digit
                    write_ptr += 1
        
        # Return the new length
        return write_ptr

# Example usage
solution = Solution()
chars1 = ["a","a","b","b","c","c","c"]
print(solution.compress(chars1))  # Output: 6, chars1 is modified to ["a","2","b","2","c","3"]

chars2 = ["a"]
print(solution.compress(chars2))  # Output: 1, chars2 remains ["a"]

chars3 = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
print(solution.compress(chars3))  # Output: 4, chars3 is modified to ["a","b","1","2"]
