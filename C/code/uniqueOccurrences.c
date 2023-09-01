/* Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000�� */


#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 2001  // Considering the range of values from -1000 to 1000

bool uniqueOccurrences(int* arr, int arrSize) {
    // Create a hash map to store occurrences of each value
    int occurrences[MAX_SIZE] = {0};
    
    // Populate the occurrences hash map
    for (int i = 0; i < arrSize; i++) {
        occurrences[arr[i] + 1000]++; // Shift by 1000 to handle negative values
    }
    
    // Create a hash set to store unique occurrences
    bool unique[MAX_SIZE] = {0};
    
    // Check for unique occurrences
    for (int i = 0; i < MAX_SIZE; i++) {
        if (occurrences[i] > 0) {
            if (unique[occurrences[i]]) {
                return false; // Non-unique occurrence found
            }
            unique[occurrences[i]] = true;
        }
    }
    
    return true; // All occurrences are unique
}

int main() {
    int arr1[] = {1, 2, 2, 1, 1, 3};
    int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Output for arr1: %s\n", uniqueOccurrences(arr1, arrSize1) ? "true" : "false");
    
    int arr2[] = {1, 2};
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Output for arr2: %s\n", uniqueOccurrences(arr2, arrSize2) ? "true" : "false");
    
    int arr3[] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    int arrSize3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Output for arr3: %s\n", uniqueOccurrences(arr3, arrSize3) ? "true" : "false");
    
    return 0;
}
