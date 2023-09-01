''' 
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.


'''




class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        count = 0  # Counter for the number of flowers that can be planted
        i = 0  # Index for iterating through the flowerbed array
        
        while i < len(flowerbed):
            # If the current plot is empty and both adjacent plots are also empty or out of bounds
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0):
                flowerbed[i] = 1  # Plant a flower in the current plot
                count += 1  # Increment the flower count
            i += 1  # Move to the next plot
        
        return count >= n  # Return True if the required number of flowers can be planted, False otherwise





# Test cases
flowerbed = [1, 0, 0, 0, 1]
n = 1
solution = Solution()
print(solution.canPlaceFlowers(flowerbed, n))  # Output: True

n = 2
print(solution.canPlaceFlowers(flowerbed, n))  # Output: False

