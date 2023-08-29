
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

// Function to check if n new flowers can be placed in the flowerbed
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0; // Counter to keep track of planted flowers
    
    // Iterate through the flowerbed
    for (int i = 0; i < flowerbedSize; ++i) {
        if (flowerbed[i] == 0) { // Check if the current plot is empty
            // Check if the previous and next positions are also empty (or out of bounds)
            int prevPos = (i == 0) ? 0 : flowerbed[i - 1];
            int nextPos = (i == flowerbedSize - 1) ? 0 : flowerbed[i + 1];
            
            if (prevPos == 0 && nextPos == 0) { // Check if adjacent positions are empty
                flowerbed[i] = 1; // Plant a flower at this position
                count++; // Increment the flower count
            }
        }
    }
    
    // Check if the required number of flowers can be placed
    return count >= n;
}

int main() {
    int flowerbed1[] = {1, 0, 0, 0, 1};
    int n1 = 1;
    printf("Result for example 1: %s\n", canPlaceFlowers(flowerbed1, sizeof(flowerbed1) / sizeof(int), n1) ? "true" : "false");

    int flowerbed2[] = {1, 0, 0, 0, 1};
    int n2 = 2;
    printf("Result for example 2: %s\n", canPlaceFlowers(flowerbed2, sizeof(flowerbed2) / sizeof(int), n2) ? "true" : "false");

    return 0;
}
