'''There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
'''
class Solution(object):
    def findCircleNum(self, isConnected):
        """
        :type isConnected: List[List[int]]
        :rtype: int
        """
        n = len(isConnected)
        visited = [0] * n
        provinces = 0

        def dfs(city):
            visited[city] = 1
            for i in range(n):
                if isConnected[city][i] == 1 and visited[i] == 0:
                    dfs(i)

        for i in range(n):
            if visited[i] == 0:
                dfs(i)
                provinces += 1

        return provinces


# Define the Solution class here...

# Test case 1
isConnected1 = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
solution1 = Solution()
provinces1 = solution1.findCircleNum(isConnected1)
print("Test case 1: Expected output 2, Actual output:", provinces1)

# Test case 2
isConnected2 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
solution2 = Solution()
provinces2 = solution2.findCircleNum(isConnected2)
print("Test case 2: Expected output 3, Actual output:", provinces2)
