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


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool increasingTriplet(int* nums, int numsSize) {
    int first = INT_MAX;  // Initialize first to a large value
    int second = INT_MAX; // Initialize second to a large value
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= first) {
            first = nums[i]; // Update the smallest element
        } else if (nums[i] <= second) {
            second = nums[i]; // Update the second smallest element
        } else {
            return true; // Found a valid triplet
        }
    }
    
    return false; // No valid triplet found
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    printf("%s\n", increasingTriplet(nums1, sizeof(nums1) / sizeof(nums1[0])) ? "true" : "false");
    
    int nums2[] = {5, 4, 3, 2, 1};
    printf("%s\n", increasingTriplet(nums2, sizeof(nums2) / sizeof(nums2[0])) ? "true" : "false");
    
    int nums3[] = {2, 1, 5, 0, 4, 6};
    printf("%s\n", increasingTriplet(nums3, sizeof(nums3) / sizeof(nums3[0])) ? "true" : "false");
    
    return 0;
}
