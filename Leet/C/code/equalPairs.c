/* Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]


Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105p */


#include <stdio.h>

int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            int isEqual = 1;
            
            for (int k = 0; k < *gridColSize; k++) {
                if (grid[i][k] != grid[k][j]) {
                    isEqual = 0;
                    break;
                }
            }
            
            if (isEqual) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int grid1[][3] = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    int gridSize1 = 3;
    int gridColSize1 = 3;

    int* ptr1[3];
    for (int i = 0; i < gridSize1; i++) {
        ptr1[i] = grid1[i];
    }

    int result1 = equalPairs(ptr1, gridSize1, &gridColSize1);
    printf("Result 1: %d\n", result1);  // Expected output: 1

    int grid2[][4] = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    int gridSize2 = 4;
    int gridColSize2 = 4;

    int* ptr2[4];
    for (int i = 0; i < gridSize2; i++) {
        ptr2[i] = grid2[i];
    }

    int result2 = equalPairs(ptr2, gridSize2, &gridColSize2);
    printf("Result 2: %d\n", result2);  // Expected output: 3

    return 0;
}
