'''You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109'''



class Solution(object):
    def maxOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        num_frequency = {}  # Hash map to store the frequency of each number
        
        operations = 0
        
        for num in nums:
            if num in num_frequency and num_frequency[num] > 0:
                # If a pair (num, k - num) is found, perform an operation
                operations += 1
                num_frequency[num] -= 1
            else:
                # Increment the frequency of the current number
                complement = k - num
                num_frequency[complement] = num_frequency.get(complement, 0) + 1
        
        return operations

# Example usage
solution = Solution()
nums1 = [1, 2, 3, 4]
k1 = 5
print(solution.maxOperations(nums1, k1))  # Output: 2

nums2 = [3, 1, 3, 4, 3]
k2 = 6
print(solution.maxOperations(nums2, k2))  # Output: 1
