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


#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int findKthLargest(int* nums, int numsSize, int k){
    int aiHash[20001] = {0};
    int iResult = 0;

    for(int iIndex = 0; iIndex < numsSize; iIndex++)
    {
        aiHash[nums[iIndex] + 10000]++;
    }

    for(int iIndex = 20000; iIndex >= 0; iIndex--)
    {
        if(aiHash[iIndex] > 0)
        {
            k = k - aiHash[iIndex];
        }
        if(k <= 0)
        {
            iResult = iIndex - 10000;
            break;
        }
    }

    return iResult;
}
int main() {
    // Test case 1
    int nums1[] = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    int result1 = findKthLargest(nums1, sizeof(nums1) / sizeof(nums1[0]), k1);
    printf("Test case 1: Kth largest element is %d\n", result1);

    // Test case 2
    int nums2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    int result2 = findKthLargest(nums2, sizeof(nums2) / sizeof(nums2[0]), k2);
    printf("Test case 2: Kth largest element is %d\n", result2);

    return 0;
}
