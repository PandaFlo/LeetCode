
/*Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
 * 
 * 
 * 
 */


/**
 * @param {number[]} nums
 * @return {boolean}
 */
var increasingTriplet = function(nums) {
    let firstMin = Number.MAX_SAFE_INTEGER; // Initialize to a large value
    let secondMin = Number.MAX_SAFE_INTEGER; // Initialize to a large value
    
    for (let num of nums) {
        if (num <= firstMin) {
            firstMin = num; // Update the first minimum
        } else if (num <= secondMin) {
            secondMin = num; // Update the second minimum
        } else {
            // If you find a number greater than both firstMin and secondMin, it's a valid triplet
            return true;
        }
    }
    
    return false; // No valid triplet found
};
console.log(increasingTriplet([1, 2, 3, 4, 5])); // Output: true
console.log(increasingTriplet([5, 4, 3, 2, 1])); // Output: false
console.log(increasingTriplet([2, 1, 5, 0, 4, 6])); // Output: true
