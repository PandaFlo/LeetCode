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
/**
 * @param {number[][]} intervals
 * @return {number}
 */
var eraseOverlapIntervals = function(intervals) {
    // Sort intervals by their end times in ascending order
    intervals.sort((a, b) => a[1] - b[1]);
    
    let count = 0; // Initialize the count of overlapping intervals
    let end = Number.MIN_SAFE_INTEGER; // Initialize the end time of the last non-overlapping interval
    
    for (const interval of intervals) {
        const start = interval[0];
        if (start >= end) {
            // If the current interval doesn't overlap with the last non-overlapping interval
            // Update the end time and increment the count
            end = interval[1];
        } else {
            // If the current interval overlaps with the last non-overlapping interval
            // Increment the count (overlapping interval to be removed)
            count++;
        }
    }
    
    return count;
};

// Test case 1
var intervals1 = [[1, 2], [2, 3], [3, 4], [1, 3]];
var result1 = eraseOverlapIntervals(intervals1);
console.log("Test Case 1:", result1, "(Expected Output: 1)");

// Test case 2
var intervals2 = [[1, 2], [1, 2], [1, 2]];
var result2 = eraseOverlapIntervals(intervals2);
console.log("Test Case 2:", result2, "(Expected Output: 2)");

// Test case 3
var intervals3 = [[1, 2], [2, 3]];
var result3 = eraseOverlapIntervals(intervals3);
console.log("Test Case 3:", result3, "(Expected Output: 0)");
