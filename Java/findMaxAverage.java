/* You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104 */


class Solution {
    public double findMaxAverage(int[] nums, int k) {
        // Calculate the initial sum of the first k elements
        int currentSum = 0;
        for (int i = 0; i < k; i++) {
            currentSum += nums[i];
        }
        double maxAverage = (double) currentSum / k; // Initialize maxAverage with the average of the first subarray
        
        // Slide the window through the array
        for (int i = k; i < nums.length; i++) {
            // Add the current element to the window sum
            currentSum += nums[i];
            // Remove the first element from the window sum
            currentSum -= nums[i - k];
            // Calculate the average of the current subarray
            double currentAverage = (double) currentSum / k;
            // Update maxAverage if the currentAverage is greater
            maxAverage = Math.max(maxAverage, currentAverage);
        }
        
        return maxAverage;
    }
}

public class findMaxAverage {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        int[] nums1 = {1, 12, -5, -6, 50, 3};
        int k1 = 4;
        System.out.println(solution.findMaxAverage(nums1, k1)); // Output: 12.75
        
        int[] nums2 = {5};
        int k2 = 1;
        System.out.println(solution.findMaxAverage(nums2, k2)); // Output: 5.0
    }
}

