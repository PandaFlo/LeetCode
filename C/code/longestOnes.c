/* Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length� */



#include <stdio.h>

int longestOnes(int* nums, int numsSize, int k) {
    int i = 0, j;  // Initialize two pointers: i (left) and j (right)
    
    // Iterate through the array using the right pointer (j)
    for (j = 0; j < numsSize; ++j) {
        // If the current element is 0, decrement the available flips (k)
        if (nums[j] == 0) {
            k--;  // Use one flip to replace the current 0 with 1
        }
        
        // If the available flips (k) becomes negative and the leftmost element is 0,
        // increment the left pointer (i) and adjust available flips (k) by incrementing it
        // (effectively restoring the used flip if the leftmost element was 0)
        if (k < 0 && nums[i++] == 0) {
            k++;  // Restore a flip by replacing the leftmost 0 with 1
              
        }
    }
    
    // The length of the subarray with consecutive ones is given by (j - i)
    return j - i;
}

int main() {
    int nums1[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("%d\n", longestOnes(nums1, numsSize1, k1));  // Output: 6

    int nums2[] = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("%d\n", longestOnes(nums2, numsSize2, k2));  // Output: 10

    return 0;
}
