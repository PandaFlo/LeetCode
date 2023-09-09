/* You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.

 

Example 1:

Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
The total hiring cost is 11.
Example 2:

Input: costs = [1,2,4,1], k = 3, candidates = 3
Output: 4
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [1,2,4,1]. The lowest cost is 1, and we break the tie by the smallest index, which is 0. The total cost = 0 + 1 = 1. Notice that workers with index 1 and 2 are common in the first and last 3 workers.
- In the second hiring round we choose the worker from [2,4,1]. The lowest cost is 1 (index 2). The total cost = 1 + 1 = 2.
- In the third hiring round there are less than three candidates. We choose the worker from the remaining workers [2,4]. The lowest cost is 2 (index 0). The total cost = 2 + 2 = 4.
The total hiring cost is 4.
 

Constraints:

1 <= costs.length <= 105 
1 <= costs[i] <= 105
1 <= k, candidates <= costs.length
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a structure for pairs (value, index)
struct Pair {
    int value;
    int index;
};

// Function to compare two pairs based on their values
int comparePairs(const void* a, const void* b) {
    return ((struct Pair*)a)->value - ((struct Pair*)b)->value;
}

long long totalCost(int* costs, int costsSize, int k, int candidates) {
    int n = costsSize;

    // Create arrays of pairs for front and back candidates
    struct Pair* fr = (struct Pair*)malloc(sizeof(struct Pair) * candidates);
    struct Pair* bk = (struct Pair*)malloc(sizeof(struct Pair) * candidates);

    long long s = 0;
    int e = n - 1;

    long long res = 0;

    long long fcnt, bcnt;
    fcnt = bcnt = candidates;

    while (k--) {
        // Fill the front candidates array
        while (s <= e && fcnt > 0) {
            fr[fcnt - 1].value = costs[s];
            fr[fcnt - 1].index = s;
            s++;
            fcnt--;
        }

        // Fill the back candidates array
        while (e >= s && bcnt > 0) {
            bk[bcnt - 1].value = costs[e];
            bk[bcnt - 1].index = e;
            e--;
            bcnt--;
        }

        // Sort the front candidates array in ascending order of values
        qsort(fr + fcnt, candidates - fcnt, sizeof(struct Pair), comparePairs);

        // Sort the back candidates array in ascending order of values
        qsort(bk + bcnt, candidates - bcnt, sizeof(struct Pair), comparePairs);

        long long v1, v2, i1, i2;
        v1 = v2 = LLONG_MAX;
        i1 = i2 = -1;

        if (fcnt < candidates) {
            v1 = fr[fcnt].value;
            i1 = fr[fcnt].index;
        }

        if (bcnt < candidates) {
            v2 = bk[bcnt].value;
            i2 = bk[bcnt].index;
        }

        if (i1 == i2) {
            v2 = INT_MAX;
            bcnt++;
        }

        if (v1 <= v2) {
            res += v1;
            fcnt++;
        } else {
            res += v2;
            bcnt++;
        }
    }

    // Clean up allocated memory
    free(fr);
    free(bk);

    return res;
}

int main() {
    // Example usage:
    int costs1[] = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    int k1 = 3;
    int candidates1 = 4;
    long long result1 = totalCost(costs1, sizeof(costs1) / sizeof(costs1[0]), k1, candidates1);
    printf("Test Case 1 Result: %lld\n", result1);  // Expected Output: 11

    int costs2[] = {1, 2, 4, 1};
    int k2 = 3;
    int candidates2 = 3;
    long long result2 = totalCost(costs2, sizeof(costs2) / sizeof(costs2[0]), k2, candidates2);
    printf("Test Case 2 Result: %lld\n", result2);  // Expected Output: 4

    return 0;
}
