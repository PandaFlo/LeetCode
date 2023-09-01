

'''
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

'''


class Solution(object):
    def productExceptSelf(self, nums):
        n = len(nums)
        result = [0] * n
        
        # Calculate left products and store them in the result array
        left_product = 1
        for i in range(n):
            result[i] = left_product
            left_product *= nums[i]
        
        # Calculate right products and multiply with left products
        right_product = 1
        for i in range(n - 1, -1, -1):
            result[i] *= right_product
            right_product *= nums[i]
        
        return result

# Example usage
nums1 = [1, 2, 3, 4]
solution = Solution()
result1 = solution.productExceptSelf(nums1)
print("Output for nums1:", result1)

nums2 = [-1, 1, 0, -3, 3]
result2 = solution.productExceptSelf(nums2)
print("Output for nums2:", result2)
