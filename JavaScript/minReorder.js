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
var minReorder = function(n, connections) {
    const graph = new Map();
    
    // Initialize the graph
    for (const [a, b] of connections) {
        if (!graph.has(a)) graph.set(a, []);
        if (!graph.has(b)) graph.set(b, []);
        graph.get(a).push([b, 1]); // Reversed edge
        graph.get(b).push([a, 0]); // Original edge
    }
    
    const dfs = (node, parent) => {
        let count = 0;
        for (const [neighbor, isReversed] of graph.get(node)) {
            if (neighbor !== parent) {
                count += isReversed; // Count reversed edges
                count += dfs(neighbor, node);
            }
        }
        return count;
    };
    
    return dfs(0, -1);
};

// Test cases
const n1 = 6;
const connections1 = [[0, 1], [1, 3], [2, 3], [4, 0], [4, 5]];
console.log(minReorder(n1, connections1));  // Output should be 3

const n2 = 5;
const connections2 = [[1, 0], [1, 2], [3, 2], [3, 4]];
console.log(minReorder(n2, connections2));  // Output should be 2

const n3 = 3;
const connections3 = [[1, 0], [2, 0]];
console.log(minReorder(n3, connections3));  // Output should be 0
