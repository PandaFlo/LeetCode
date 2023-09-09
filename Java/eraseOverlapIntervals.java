/* Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

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
 */


 import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }

        // Sort intervals by their end points
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));

        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < end) {
                // Overlapping interval found, remove it
                count++;
            } else {
                // No overlap, update the end point
                end = intervals[i][1];
            }
        }

        return count;
    }
}


public class eraseOverlapIntervals {
public static void main(String[] args) {
    Solution solution = new Solution();

    int[][] intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result1 = solution.eraseOverlapIntervals(intervals1);
    System.out.println("Test Case 1: " + result1); // Expected output: 1

    int[][] intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    int result2 = solution.eraseOverlapIntervals(intervals2);
    System.out.println("Test Case 2: " + result2); // Expected output: 2

    int[][] intervals3 = {{1, 2}, {2, 3}};
    int result3 = solution.eraseOverlapIntervals(intervals3);
    System.out.println("Test Case 3: " + result3); // Expected output: 0
}

}