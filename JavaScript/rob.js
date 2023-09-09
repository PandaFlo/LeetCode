/* You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
 */
var rob = function(nums) {
    if (!nums || nums.length === 0) {
        return 0;
    }
    
    const n = nums.length;
    
    if (n === 1) {
        return nums[0];
    }
    
    // Create an array to store the maximum amount robbed up to each house.
    const maxRobbed = new Array(n);
    
    // Initialize the first two values in the maxRobbed array.
    maxRobbed[0] = nums[0];
    maxRobbed[1] = Math.max(nums[0], nums[1]);
    
    // Iterate through the houses to calculate the maximum amount robbed.
    for (let i = 2; i < n; i++) {
        maxRobbed[i] = Math.max(maxRobbed[i - 1], maxRobbed[i - 2] + nums[i]);
    }
    
    // The last element of maxRobbed array contains the maximum amount robbed without alerting the police.
    return maxRobbed[n - 1];
};

// Example usage:
const nums1 = [1, 2, 3, 1];
console.log(rob(nums1));  // Output: 4

const nums2 = [2, 7, 9, 3, 1];
console.log(rob(nums2));  // Output: 12
