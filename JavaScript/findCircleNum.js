/* There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

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
 */
/**
 * @param {number[][]} isConnected
 * @return {number}
 */
var findCircleNum = function(isConnected) {
    const n = isConnected.length;
    const visited = new Array(n).fill(0);
    let provinces = 0;

    for (let i = 0; i < n; i++) {
        if (visited[i] === 0) {
            dfs(isConnected, visited, i);
            provinces++;
        }
    }

    return provinces;
};

function dfs(isConnected, visited, city) {
    visited[city] = 1;
    for (let i = 0; i < isConnected.length; i++) {
        if (isConnected[city][i] === 1 && visited[i] === 0) {
            dfs(isConnected, visited, i);
        }
    }
};

// Function definition here...

// Test case 1
const isConnected1 = [[1, 1, 0], [1, 1, 0], [0, 0, 1]];
const provinces1 = findCircleNum(isConnected1);
console.log("Test case 1: Expected output 2, Actual output:", provinces1);

// Test case 2
const isConnected2 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
const provinces2 = findCircleNum(isConnected2);
console.log("Test case 2: Expected output 3, Actual output:", provinces2);
