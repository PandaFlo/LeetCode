
/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

*/
#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Calculate left products and store them in the result array
    int leftProduct = 1;
    for (int i = 0; i < numsSize; i++) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }
    
    // Calculate right products and multiply with left products
    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}

int main() {
    int nums1[] = {1, 2, 3, 4};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    int* result1 = productExceptSelf(nums1, numsSize1, &returnSize1);
    
    printf("Output for nums1: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    
    int nums2[] = {-1, 1, 0, -3, 3};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    int* result2 = productExceptSelf(nums2, numsSize2, &returnSize2);
    
    printf("Output for nums2: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    
    free(result1);
    free(result2);
    
    return 0;
}
