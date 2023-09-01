/* You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters and stars *.
The operation above can be performed on s. */


#include <stdio.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* result = (int*)malloc(asteroidsSize * sizeof(int)); // Allocate memory for the result array
    *returnSize = 0; // Initialize the returnSize to 0

    for (int i = 0; i < asteroidsSize; ++i) {
        int currentAsteroid = asteroids[i];

        if (*returnSize == 0 || currentAsteroid > 0) {
            // If the result array is empty or the current asteroid is positive, add it to the result
            result[(*returnSize)++] = currentAsteroid;
        } else {
            while (*returnSize > 0 && result[*returnSize - 1] > 0 && result[*returnSize - 1] < -currentAsteroid) {
                // Handle collision conditions
                (*returnSize)--;
            }

            if (*returnSize == 0 || result[*returnSize - 1] < 0) {
                result[(*returnSize)++] = currentAsteroid;
            } else if (result[*returnSize - 1] == -currentAsteroid) {
                (*returnSize)--;
            }
        }
    }

    return result;
}

int main() {
    int asteroids1[] = {5, 10, -5};
    int size1 = sizeof(asteroids1) / sizeof(asteroids1[0]);
    int returnSize1;

    int* result1 = asteroidCollision(asteroids1, size1, &returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        printf("%d ", result1[i]);
    }
    printf("\n"); // Output: 5 10

    // Repeat similar steps for the other test cases

    // Free dynamically allocated memory
    free(result1);

    return 0;
}
