'''You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104'''


class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        # Calculate the initial sum of the first k elements
        current_sum = sum(nums[:k])
        max_average = current_sum / float(k)  # Initialize max_average with the average of the first subarray

        # Slide the window through the array
        for i in range(k, len(nums)):
            # Add the current element to the window sum
            current_sum += nums[i]
            # Remove the first element from the window sum
            current_sum -= nums[i - k]
            # Calculate the average of the current subarray
            current_average = current_sum / float(k)
            # Update max_average if the current_average is greater
            max_average = max(max_average, current_average)

        return max_average

# Example usage
nums = [1, 12, -5, -6, 50, 3]
k = 4
solution = Solution()
result = solution.findMaxAverage(nums, k)
print(result)

