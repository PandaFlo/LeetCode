/* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
 */


var findKthLargest = function(nums, k) {
    nums.sort((a, b) => b - a); // Sort the array in descending order
    return nums[k - 1]; // Return the kth largest element
};

function testFindKthLargest() {
    // Test case 1
    const nums1 = [3, 2, 1, 5, 6, 4];
    const k1 = 2;
    const result1 = findKthLargest(nums1, k1);
    console.log("Test case 1: Kth largest element is " + result1);

    // Test case 2
    const nums2 = [3, 2, 3, 1, 2, 4, 5, 5, 6];
    const k2 = 4;
    const result2 = findKthLargest(nums2, k2);
    console.log("Test case 2: Kth largest element is " + result2);

    // Add more test cases here if needed
}

// Run the tester function
testFindKthLargest();
