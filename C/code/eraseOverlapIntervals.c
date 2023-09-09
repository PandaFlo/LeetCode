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


#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct {
    int start;
    int end;
} Interval;

// Compare function for sorting intervals based on their end values
int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->end - ((Interval*)b)->end;
}

int eraseOverlapIntervals(Interval* intervals, int intervalsSize) {
    if (intervalsSize <= 1) {
        return 0;  // No overlaps to remove
    }

    // Sort intervals based on their end values
    qsort(intervals, intervalsSize, sizeof(Interval), compareIntervals);

    int count = 1;  // Count of non-overlapping intervals
    int end = intervals[0].end;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i].start >= end) {
            count++;
            end = intervals[i].end;
        }
    }

    // Calculate the number of intervals to remove
    return intervalsSize - count;
}

int main() {
    // Test case 1
    Interval intervals1[] = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int intervalsSize1 = sizeof(intervals1) / sizeof(intervals1[0]);
    int result1 = eraseOverlapIntervals(intervals1, intervalsSize1);
    printf("Test case 1: %d\n", result1);  // Expected output: 1

    // Test case 2
    Interval intervals2[] = {{1, 2}, {1, 2}, {1, 2}};
    int intervalsSize2 = sizeof(intervals2) / sizeof(intervals2[0]);
    int result2 = eraseOverlapIntervals(intervals2, intervalsSize2);
    printf("Test case 2: %d\n", result2);  // Expected output: 2

    // Test case 3
    Interval intervals3[] = {{1, 2}, {2, 3}};
    int intervalsSize3 = sizeof(intervals3) / sizeof(intervals3[0]);
    int result3 = eraseOverlapIntervals(intervals3, intervalsSize3);
    printf("Test case 3: %d\n", result3);  // Expected output: 0

    return 0;
}
