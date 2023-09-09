/* Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
 */


#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)malloc(temperaturesSize * sizeof(int));
    *returnSize = temperaturesSize;

    // Initialize the result array to zeros
    for (int i = 0; i < temperaturesSize; i++) {
        result[i] = 0;
    }

    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int j = stack[top--];
            result[j] = i - j;
        }
        stack[++top] = i;
    }

    free(stack);
    return result;
}

int main() {
    int temperatures1[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int returnSize1;
    int* output1 = dailyTemperatures(temperatures1, sizeof(temperatures1) / sizeof(int), &returnSize1);
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", output1[i]);
    }
    free(output1);

    int temperatures2[] = {30, 40, 50, 60};
    int returnSize2;
    int* output2 = dailyTemperatures(temperatures2, sizeof(temperatures2) / sizeof(int), &returnSize2);
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", output2[i]);
    }
    free(output2);

    int temperatures3[] = {30, 60, 90};
    int returnSize3;
    int* output3 = dailyTemperatures(temperatures3, sizeof(temperatures3) / sizeof(int), &returnSize3);
    for (int i = 0; i < returnSize3; i++) {
        printf("%d ", output3[i]);
    }
    free(output3);

    return 0;
}
