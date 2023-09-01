'''Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length�'''


class Solution(object):
    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        i = 0  # Initialize the left pointer
        max_length = 0  # To keep track of the maximum consecutive ones
        
        # Iterate through the list using the right pointer
        for j in range(len(nums)):
            if nums[j] == 0:
                k -= 1  # Decrement available flips (k)
                
                # If available flips become negative, move the left pointer
                # while restoring flips if the leftmost element was 0
                while k < 0:
                    if nums[i] == 0:
                        k += 1
                    i += 1
            
            # Calculate the maximum length of consecutive ones
            max_length = max(max_length, j - i + 1)
        
        return max_length

def test_solution():
    solution = Solution()
    
    nums1 = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0]
    k1 = 2
    result1 = solution.longestOnes(nums1, k1)
    print("Test case 1: Result =", result1, "Expected =", 6)
    
    nums2 = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1]
    k2 = 3
    result2 = solution.longestOnes(nums2, k2)
    print("Test case 2: Result =", result2, "Expected =", 10)
    
    if result1 == 6 and result2 == 10:
        print("All test cases passed!")
    else:
        print("Some test cases failed!")

if __name__ == "__main__":
    test_solution()
