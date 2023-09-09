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
#include <stdio.h>
#include <stdlib.h>

int rob(int* nums, int numsSize);
int rob(int* nums, int numsSize) {
    if (!nums || numsSize == 0) {
        return 0;
    }
    
    if (numsSize == 1) {
        return nums[0];
    }
    
    // Create an array to store the maximum amount robbed up to each house.
    int* maxRobbed = (int*)malloc(numsSize * sizeof(int));
    
    // Initialize the first two values in the maxRobbed array.
    maxRobbed[0] = nums[0];
    maxRobbed[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    
    // Iterate through the houses to calculate the maximum amount robbed.
    for (int i = 2; i < numsSize; i++) {
        maxRobbed[i] = maxRobbed[i - 1] > maxRobbed[i - 2] + nums[i] ? maxRobbed[i - 1] : maxRobbed[i - 2] + nums[i];
    }
    
    // The last element of maxRobbed array contains the maximum amount robbed without alerting the police.
    int result = maxRobbed[numsSize - 1];
    
    free(maxRobbed); // Free the dynamically allocated memory.
    
    return result;
}

void tester() {
    // Test cases
    int testCases1[] = {1, 2, 3, 1};
    int testCases2[] = {2, 7, 9, 3, 1};

    int result1 = rob(testCases1, sizeof(testCases1) / sizeof(testCases1[0]));
    int result2 = rob(testCases2, sizeof(testCases2) / sizeof(testCases2[0]));

    printf("Maximum amount for test case 1: %d\n", result1);
    printf("Maximum amount for test case 2: %d\n", result2);
}

int main() {
    tester();
    return 0;
}
