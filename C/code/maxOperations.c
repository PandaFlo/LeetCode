/* You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109 */



#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    
{
    int num1 = *(int *)a;   
    int num2 = *(int *)b;   

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int maxOperations(int* nums, int numsSize, int k){
    int ret=0;
    int l=0, r=numsSize-1;

    qsort(nums, numsSize, sizeof(int), compare);

    while(l < r){
        if(nums[l]+nums[r] == k) {
            l++;
            r--;
            ret++;
        }
        else if(nums[l]+nums[r] > k) r--;
        else l++;
    }
    return ret;

}

int main() {
    int nums1[] = {1, 2, 3, 4};
    int k1 = 5;
    printf("Output 1: %d\n", maxOperations(nums1, sizeof(nums1) / sizeof(nums1[0]), k1)); // Output: 2

    int nums2[] = {3, 1, 3, 4, 3};
    int k2 = 6;
    printf("Output 2: %d\n", maxOperations(nums2, sizeof(nums2) / sizeof(nums2[0]), k2)); // Output: 1

    return 0;
}
