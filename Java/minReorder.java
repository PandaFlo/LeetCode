/* There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

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
 */
import java.util.ArrayList;
import java.util.List;




class Solution {
    public int minReorder(int n, int[][] connections) {
        List<List<int[]>> graph = new ArrayList<>();
        
        // Initialize the graph
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        
        // Create an adjacency list to represent the tree
        for (int[] connection : connections) {
            int a = connection[0];
            int b = connection[1];
            graph.get(a).add(new int[] {b, 1});  // Reversed edge
            graph.get(b).add(new int[] {a, 0});  // Original edge
        }
        
        return dfs(0, -1, graph);
    }
    
    private int dfs(int node, int parent, List<List<int[]>> graph) {
        int count = 0;
        for (int[] neighborInfo : graph.get(node)) {
            int neighbor = neighborInfo[0];
            int isReversed = neighborInfo[1];
            if (neighbor != parent) {
                count += isReversed;  // Count reversed edges
                count += dfs(neighbor, node, graph);
            }
        }
        return count;
    }
}


public class minReorder {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test cases
        int n1 = 6;
        int[][] connections1 = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
        System.out.println(solution.minReorder(n1, connections1));  // Output should be 3

        int n2 = 5;
        int[][] connections2 = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
        System.out.println(solution.minReorder(n2, connections2));  // Output should be 2

        int n3 = 3;
        int[][] connections3 = {{1, 0}, {2, 0}};
        System.out.println(solution.minReorder(n3, connections3));  // Output should be 0
    }
}

