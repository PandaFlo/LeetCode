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


#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0; // No intervals to remove.
        }
        
        // Sort intervals by their end times.
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        int count = 1; // Count of non-overlapping intervals.
        int end = intervals[0][1]; // End time of the first interval.
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                // If the current interval doesn't overlap with the previous one,
                // update the end time and increment the count.
                end = intervals[i][1];
                count++;
            }
        }
        
        // Calculate the number of intervals to remove.
        int toRemove = intervals.size() - count;
        return toRemove;
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::vector<std::vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result1 = solution.eraseOverlapIntervals(intervals1);
    std::cout << "Test Case 1: " << result1 << " (Expected Output: 1)" << std::endl;

    // Test case 2
    std::vector<std::vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    int result2 = solution.eraseOverlapIntervals(intervals2);
    std::cout << "Test Case 2: " << result2 << " (Expected Output: 2)" << std::endl;

    // Test case 3
    std::vector<std::vector<int>> intervals3 = {{1, 2}, {2, 3}};
    int result3 = solution.eraseOverlapIntervals(intervals3);
    std::cout << "Test Case 3: " << result3 << " (Expected Output: 0)" << std::endl;

    return 0;
}