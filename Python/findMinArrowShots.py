'''There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 

Constraints:

1 <= points.length <= 105
points[i].length == 2
-231 <= xstart < xend <= 231 - 1
'''



class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        end = float('-inf')
        count = 0
        for s, e in sorted(points, key = lambda x: x[1]):
            if s > end:
                end = e
                count += 1
        return count
            


# Create an instance of the Solution class
solution = Solution()

# Test case 1
points1 = [[10, 16], [2, 8], [1, 6], [7, 12]]
result1 = solution.findMinArrowShots(points1)
print("Test case 1 result:", result1)  # Expected output: 2

# Test case 2
points2 = [[1, 2], [3, 4], [5, 6], [7, 8]]
result2 = solution.findMinArrowShots(points2)
print("Test case 2 result:", result2)  # Expected output: 4

# Test case 3
points3 = [[1, 2], [2, 3], [3, 4], [4, 5]]
result3 = solution.findMinArrowShots(points3)
print("Test case 3 result:", result3)  # Expected output: 2
