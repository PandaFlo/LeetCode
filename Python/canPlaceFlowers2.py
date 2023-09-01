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
        flowerbed = [1, 0] + flowerbed + [0, 1]
        
        maxi = 0
        cur = 0
        for num in flowerbed:
            if num == 0:
                cur += 1
            else:
                if cur > 2:
                    maxi += (cur - 2) // 2 + (cur % 2 > 0)
                cur = 0

        if n <= maxi:
            return True
        return False



# Test cases
flowerbed = [1, 0, 0, 0, 1]
n = 1
solution = Solution()
print(solution.canPlaceFlowers(flowerbed, n))  # Output: True

n = 2
print(solution.canPlaceFlowers(flowerbed, n))  # Output: False

