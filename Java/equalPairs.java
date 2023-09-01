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


class Solution {
    public int equalPairs(int[][] grid) {
        int count = 0;
        int n = grid.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                boolean isEqual = true;

                for (int k = 0; k < n; k++) {
                    if (grid[i][k] != grid[k][j]) {
                        isEqual = false;
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
}

public class equalPairs {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[][] grid1 = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
        int result1 = solution.equalPairs(grid1);
        System.out.println("Result 1: " + result1);  // Expected output: 1

        int[][] grid2 = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
        int result2 = solution.equalPairs(grid2);
        System.out.println("Result 2: " + result2);  // Expected output: 3
    }
}
