/* Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105
 

Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
 */
#include <stdio.h>
#include <stdlib.h>
int* countBits(int n, int* returnSize) {
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        // To calculate the count of 1's in binary representation of i,
        // use the fact that dp[i] = dp[i >> 1] + (i & 1).
        dp[i] = dp[i >> 1] + (i & 1);
    }

    return dp;
}
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void tester() {
    int testCases[] = {0, 1, 2, 5, 10};
    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTestCases; i++) {
        int n = testCases[i];
        int returnSize;
        int* result = countBits(n, &returnSize);

        printf("n = %d, Output: ", n);
        printArray(result, returnSize);

        free(result); // Free the allocated memory
    }
}

int main() {
    tester();
    return 0;
}
