
/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

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
