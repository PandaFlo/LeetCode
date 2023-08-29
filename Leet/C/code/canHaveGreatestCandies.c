
/*
There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

 

Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
 

Constraints:

n == candies.length
2 <= n <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50

*/



#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int maximum(int arr[], int sz) {
    int max = 0;
    for (int i = 0; i < sz; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

// Function to determine if each kid can have the most candies with extras
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    // Allocate memory for the result array
    bool* arr = (bool*)malloc(sizeof(bool) * candiesSize);
    
    // Find the maximum number of candies among all kids
    int max = maximum(candies, candiesSize);
    
    // Determine if each kid can have the most candies
    for (int i = 0; i < candiesSize; i++) {
        arr[i] = extraCandies + candies[i] >= max;
    }
    
    // Set the return size and return the result array
    *returnSize = candiesSize;
    return arr;
}

int main() {
    // Sample input: initial candies, extra candies, and number of kids
    int candies[] = {2, 3, 5, 1, 3};
    int candiesSize = sizeof(candies) / sizeof(candies[0]);
    int extraCandies = 3;
    int returnSize; // To store the size of the result array
    
    // Calculate if each kid can have the most candies with extras
    bool* result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);

    // Display the original candies
    printf("Original Candies: ");
    for (int i = 0; i < candiesSize; i++) {
        printf("%d ", candies[i]);
    }
    printf("\n");

    // Display the result after giving extra candies
    printf("After Giving Extra Candies:\n");
    for (int i = 0; i < candiesSize; i++) {
        printf("Kid %d can have the most candies: %s\n", i, result[i] ? "true" : "false");
    }

    // Free the dynamically allocated memory for the result array
    free(result);

    return 0;
}
