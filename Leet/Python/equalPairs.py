'''Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

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

1 <= grid[i][j] <= 105p'''




class Solution(object):
    def equalPairs(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        count = 0
        n = len(grid)

        for i in range(n):
            for j in range(n):
                isEqual = True

                for k in range(n):
                    if grid[i][k] != grid[k][j]:
                        isEqual = False
                        break

                if isEqual:
                    count += 1

        return count

def tester():
    solution = Solution()

    grid1 = [[3, 2, 1], [1, 7, 6], [2, 7, 7]]
    result1 = solution.equalPairs(grid1)
    print("Result 1:", result1)  # Expected output: 1

    grid2 = [[3, 1, 2, 2], [1, 4, 4, 5], [2, 4, 2, 2], [2, 4, 2, 2]]
    result2 = solution.equalPairs(grid2)
    print("Result 2:", result2)  # Expected output: 3

tester()
