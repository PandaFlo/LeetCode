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


#include <stdio.h>
#include <stdlib.h>

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    // Create space for the two result lists
    int* list1 = (int*)malloc(nums1Size * sizeof(int));
    int* list2 = (int*)malloc(nums2Size * sizeof(int));
    int list1Size = 0;
    int list2Size = 0;

    // Create sets to store distinct elements
    int* set1 = (int*)malloc(nums1Size * sizeof(int));
    int* set2 = (int*)malloc(nums2Size * sizeof(int));
    int setSize1 = 0;
    int setSize2 = 0;

    // Populate set1
    for (int i = 0; i < nums1Size; i++) {
        int num = nums1[i];
        int found = 0;
        for (int j = 0; j < setSize1; j++) {
            if (set1[j] == num) {
                found = 1;
                break;
            }
        }
        if (!found) {
            set1[setSize1++] = num;
        }
    }

    // Populate set2
    for (int i = 0; i < nums2Size; i++) {
        int num = nums2[i];
        int found = 0;
        for (int j = 0; j < setSize2; j++) {
            if (set2[j] == num) {
                found = 1;
                break;
            }
        }
        if (!found) {
            set2[setSize2++] = num;
        }
    }

    // Find differences for list1
    for (int i = 0; i < setSize1; i++) {
        int num = set1[i];
        int found = 0;
        for (int j = 0; j < setSize2; j++) {
            if (set2[j] == num) {
                found = 1;
                break;
            }
        }
        if (!found) {
            list1[list1Size++] = num;
        }
    }

    // Find differences for list2
    for (int i = 0; i < setSize2; i++) {
        int num = set2[i];
        int found = 0;
        for (int j = 0; j < setSize1; j++) {
            if (set1[j] == num) {
                found = 1;
                break;
            }
        }
        if (!found) {
            list2[list2Size++] = num;
        }
    }

    // Prepare the return arrays
    int** result = (int**)malloc(2 * sizeof(int*));
    result[0] = list1;
    result[1] = list2;

    *returnSize = 2;

    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = list1Size;
    (*returnColumnSizes)[1] = list2Size;

    return result;
}

int main() {
    int nums1[] = {1, 2, 3};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2, 4, 6};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** result = findDifference(nums1, nums1Size, nums2, nums2Size, &returnSize, &returnColumnSizes);

    // Print the results for the first example
    printf("Example 1:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }

    // Free memory for the first example
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    // Example 2
    int nums3[] = {1, 2, 3, 3};
    int nums3Size = sizeof(nums3) / sizeof(nums3[0]);
    int nums4[] = {1, 1, 2, 2};
    int nums4Size = sizeof(nums4) / sizeof(nums4[0]);
    returnSize = 0;
    returnColumnSizes = NULL;

    result = findDifference(nums3, nums3Size, nums4, nums4Size, &returnSize, &returnColumnSizes);

    // Print the results for the second example
    printf("\nExample 2:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }

    // Free memory for the second example
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}
