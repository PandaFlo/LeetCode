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


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function(nums, k) {
    // Calculate the initial sum of the first k elements
    let currentSum = 0;
    for (let i = 0; i < k; i++) {
        currentSum += nums[i];
    }
    let maxAverage = currentSum / k; // Initialize maxAverage with the average of the first subarray
    
    // Slide the window through the array
    for (let i = k; i < nums.length; i++) {
        // Add the current element to the window sum
        currentSum += nums[i];
        // Remove the first element from the window sum
        currentSum -= nums[i - k];
        // Calculate the average of the current subarray
        let currentAverage = currentSum / k;
        // Update maxAverage if the currentAverage is greater
        maxAverage = Math.max(maxAverage, currentAverage);
    }
    
    return maxAverage;
};

// Example usage
const nums1 = [1, 12, -5, -6, 50, 3];
const k1 = 4;
console.log(findMaxAverage(nums1, k1)); // Output: 12.75

const nums2 = [5];
const k2 = 1;
console.log(findMaxAverage(nums2, k2)); // Output: 5.0
