/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done? */




var moveZeroes = function(nums) {
    let nonZeroIndex = 0; // Index to keep track of the last non-zero element

    // Loop through the array
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            // If the current element is non-zero, swap it with the element at nonZeroIndex
            let temp = nums[nonZeroIndex];
            nums[nonZeroIndex] = nums[i];
            nums[i] = temp;

            nonZeroIndex++; // Move the nonZeroIndex forward
        }
    }
};

// Test cases
let nums1 = [0, 1, 0, 3, 12];
moveZeroes(nums1);
console.log(nums1); // Output: [1, 3, 12, 0, 0]

let nums2 = [0];
moveZeroes(nums2);
console.log(nums2); // Output: [0]
