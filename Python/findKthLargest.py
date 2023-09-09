'''Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
'''

import heapq

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #count sorting
        max_num, min_num = max(nums), min(nums)
        
        count = [0]*(max_num-min_num+1)
        
        for num in nums:
            count[num-min_num] += 1
        
        n = len(count)
        for i in range(n-1, -1 ,-1):
            k -= count[i]
            
            if k <= 0:
                return i+min_num
        
        return -1
        
        


def test_findKthLargest():
    solution = Solution()

    # Test case 1
    nums1 = [3, 2, 1, 5, 6, 4]
    k1 = 2
    result1 = solution.findKthLargest(nums1, k1)
    print("Test case 1:")
    print("Input:", nums1)
    print("k:", k1)
    print("Expected Output: 5")
    print("Actual Output:", result1)
    print()

    # Test case 2
    nums2 = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k2 = 4
    result2 = solution.findKthLargest(nums2, k2)
    print("Test case 2:")
    print("Input:", nums2)
    print("k:", k2)
    print("Expected Output: 4")
    print("Actual Output:", result2)
    print()

    # Add more test cases here if needed

test_findKthLargest()

    

