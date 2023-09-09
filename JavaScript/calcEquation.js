/* You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 */


/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */

var calcEquation = function(equations, values, queries) {
    const adjList = new Map();
    
    // Initialize the graph
    for (let i = 0; i < equations.length; i++) {
        adjList.set(equations[i][0], []);
        adjList.set(equations[i][1], []);
    }

    // Build the graph
    for (let i = 0; i < equations.length; i++) {
        const u = equations[i][0];
        const v = equations[i][1];
        const weight = values[i];
        
        // u to v
        adjList.get(u).push([v,weight]);
        
        // v to u
        adjList.get(v).push([u, 1/weight]);
    }
    
    // Initialize results array
    const res = [];
    
    for (let i = 0; i < queries.length; i++) {
        // divisor
        const src = queries[i][0];
        
        // dividend
        const dest = queries[i][1];
        const seen = new Set();
        const val = dfs(adjList, src, src, dest, 1, seen);
        
        
        if (val === false) {
            res.push(-1);
        } else {
            res.push(val);
        }
    }
    
    return res;
}
// In the case that there are other multiple valid paths from source to destination, ultimately, the quotient is the same
// returning the first then works.
var dfs = function(adjList, src, curr, dest, quotient, seen) {
    //destination or source is non existent
    if (!adjList.has(dest) || !adjList.has(src)) {
        return -1;
    }
    
    //source is same as destination i.e. self-loop.
    if (src === dest) {
        return 1;
    }
    
    // Reached destination
    if (curr === dest) {
        return quotient;
    }
    
    seen.add(curr);
    
    const neighbors = adjList.get(curr);
    
    for (let i = 0; i < neighbors.length; i++) {
        if (seen.has(neighbors[i][0])) {
            continue;
        }
        const val = dfs(adjList, src, neighbors[i][0], dest, quotient * neighbors[i][1], seen);
        // if any value was found we return because
        // the only other cases would be having a cycle, or reaching our destination or path.
        if (val !== false) return val;
    }
    
    // We only return false if we've searched all neighbors and there's no path to destination
    // however we know that src and dest are in adjList
    // thus it may just be disconnected, but this may return from different levels of recursion.
    return false;
}


// Example 1
const equations1 = [["a","b"],["b","c"]];
const values1 = [2.0, 3.0];
const queries1 = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]];
console.log(calcEquation(equations1, values1, queries1)); // Expected output: [6.0, 0.5, -1.0, 1.0, -1.0]

// Example 2
const equations2 = [["a","b"],["b","c"],["bc","cd"]];
const values2 = [1.5, 2.5, 5.0];
const queries2 = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]];
console.log(calcEquation(equations2, values2, queries2)); // Expected output: [3.75, 0.4, 5.0, 0.2]

// Example 3
const equations3 = [["a","b"]];
const values3 = [0.5];
const queries3 = [["a","b"],["b","a"],["a","c"],["x","y"]];
console.log(calcEquation(equations3, values3, queries3)); // Expected output: [0.5, 2.0, -1.0, -1.0]