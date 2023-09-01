'''Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.�?��'''


class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_length = 0
        left = 0  # Left pointer of the sliding window
        count_zeros = 0  # Count of zeros in the current window
        
        for right in range(len(nums)):
            if nums[right] == 0:
                count_zeros += 1
            
            # Shrink the window if there's more than one zero
            while count_zeros > 1:
                if nums[left] == 0:
                    count_zeros -= 1
                left += 1
            
            max_length = max(max_length, right - left)
        
        return max_length

# Test cases
solution = Solution()
print(solution.longestSubarray([1, 1, 0, 1]))  # Output: 3
print(solution.longestSubarray([0, 1, 1, 1, 0, 1, 1, 0, 1]))  # Output: 5
print(solution.longestSubarray([1, 1, 1]))  # Output: 2
