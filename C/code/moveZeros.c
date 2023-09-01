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



#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int nonZeroIndex = 0;  // Index to track the position of the next non-zero element
    
    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            // If the current element is non-zero, move it to the nonZeroIndex position
            nums[nonZeroIndex] = nums[i];
            nonZeroIndex++;
        }
    }
    
    // Fill the rest of the array with zeros
    for (int i = nonZeroIndex; i < numsSize; i++) {
        nums[i] = 0;
    }
}

int main() {
    int nums1[] = {0, 1, 0, 3, 12};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);

    moveZeroes(nums1, numsSize1);

    printf("Result 1: ");
    for (int i = 0; i < numsSize1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    int nums2[] = {0};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);

    moveZeroes(nums2, numsSize2);

    printf("Result 2: ");
    for (int i = 0; i < numsSize2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return 0;
}
