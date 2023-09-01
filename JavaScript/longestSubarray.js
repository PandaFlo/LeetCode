/* Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.�?�� */

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let max_length = 0;
    let left = 0; // Left pointer of the sliding window
    let count_zeros = 0; // Count of zeros in the current window
    
    for (let right = 0; right < nums.length; right++) {
        if (nums[right] === 0) {
            count_zeros++;
        }
        
        // Shrink the window if there's more than one zero
        while (count_zeros > 1) {
            if (nums[left] === 0) {
                count_zeros--;
            }
            left++;
        }
        
        max_length = Math.max(max_length, right - left);
    }
    
    return max_length;
};

// Test cases
console.log(longestSubarray([1, 1, 0, 1])); // Output: 3
console.log(longestSubarray([0, 1, 1, 1, 0, 1, 1, 0, 1])); // Output: 5
console.log(longestSubarray([1, 1, 1])); // Output: 2
