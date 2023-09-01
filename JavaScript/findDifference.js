/* Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

 

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
 

Constraints:

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000 */


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[][]}
 */
var findDifference = function(nums1, nums2) {
    let ans1 = new Set(nums1);
    let ans2 = new Set(nums2);
    nums1.forEach((v) => ans2.delete(v));
    nums2.forEach((v) => ans1.delete(v));
    return [[...ans1], [...ans2]];
};

// Test the examples
let nums1 = [1, 2, 3];
let nums2 = [2, 4, 6];
let result1 = findDifference(nums1, nums2);
console.log("Example 1:");
console.log(result1);

let nums3 = [1, 2, 3, 3];
let nums4 = [1, 1, 2, 2];
let result2 = findDifference(nums3, nums4);
console.log("\nExample 2:");
console.log(result2);
