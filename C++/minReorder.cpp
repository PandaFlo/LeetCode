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
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        
        // Initialize the graph
        for (const vector<int>& connection : connections) {
            int a = connection[0];
            int b = connection[1];
            graph[a].emplace_back(b, 1);  // Reversed edge
            graph[b].emplace_back(a, 0);  // Original edge
        }
        
        function<int(int, int)> dfs = [&](int node, int parent) {
            int count = 0;
            for (const pair<int, int>& neighborInfo : graph[node]) {
                int neighbor = neighborInfo.first;
                int isReversed = neighborInfo.second;
                if (neighbor != parent) {
                    count += isReversed;  // Count reversed edges
                    count += dfs(neighbor, node);
                }
            }
            return count;
        };
        
        return dfs(0, -1);
    }
};

int main() {
    Solution solution;

    // Test cases
    int n1 = 6;
    vector<vector<int>> connections1 = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    cout << solution.minReorder(n1, connections1) << endl;  // Output should be 3

    int n2 = 5;
    vector<vector<int>> connections2 = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
    cout << solution.minReorder(n2, connections2) << endl;  // Output should be 2

    int n3 = 3;
    vector<vector<int>> connections3 = {{1, 0}, {2, 0}};
    cout << solution.minReorder(n3, connections3) << endl;  // Output should be 0

    return 0;
}
