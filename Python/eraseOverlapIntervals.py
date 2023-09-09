'''Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
'''
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if not intervals:
            return 0
        
        # Sort intervals based on their end values
        intervals.sort(key=lambda x: x[1])
        
        count = 1  # Count of non-overlapping intervals
        end = intervals[0][1]
        
        for i in range(1, len(intervals)):
            if intervals[i][0] >= end:
                count += 1
                end = intervals[i][1]
        
        # Calculate the number of intervals to remove
        return len(intervals) - count


# Create an instance of the Solution class
solution = Solution()

# Test case 1
intervals1 = [[1, 2], [2, 3], [3, 4], [1, 3]]
result1 = solution.eraseOverlapIntervals(intervals1)
print("Test case 1:", result1)
# Expected output: 1

# Test case 2
intervals2 = [[1, 2], [1, 2], [1, 2]]
result2 = solution.eraseOverlapIntervals(intervals2)
print("Test case 2:", result2)
# Expected output: 2

# Test case 3
intervals3 = [[1, 2], [2, 3]]
result3 = solution.eraseOverlapIntervals(intervals3)
print("Test case 3:", result3)
# Expected output: 0
