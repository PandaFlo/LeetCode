'''There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

 

Example 1:
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
 

Constraints:

2 <= n <= 5 * 104
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
'''
class Solution(object):
    def minReorder(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        graph = [[] for _ in range(n)]
        
        # Create an adjacency list to represent the tree
        for a, b in connections:
            graph[a].append((b, 1))  # Reversed edge
            graph[b].append((a, 0))  # Original edge
        
        def dfs(node, parent):
            count = 0
            for neighbor, is_reversed in graph[node]:
                if neighbor != parent:
                    count += is_reversed  # Count reversed edges
                    count += dfs(neighbor, node)
            return count
        
        return dfs(0, -1)


# Create an instance of the Solution class
sol = Solution()

# Test cases
n1 = 6
connections1 = [[0, 1], [1, 3], [2, 3], [4, 0], [4, 5]]
print(sol.minReorder(n1, connections1))  # Output should be 3

n2 = 5
connections2 = [[1, 0], [1, 2], [3, 2], [3, 4]]
print(sol.minReorder(n2, connections2))  # Output should be 2

n3 = 3
connections3 = [[1, 0], [2, 0]]
print(sol.minReorder(n3, connections3))  # Output should be 0
