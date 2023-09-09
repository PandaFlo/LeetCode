/* There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
 

Constraints:

n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.
*/

/**
 * @param {number[][]} rooms
 * @return {boolean}
 */
var canVisitAllRooms = function(rooms) {
    const n = rooms.length;
    const visited = new Array(n).fill(false);
    
    const stack = [0]; // Start with room 0
    
    while (stack.length > 0) {
        const currentRoom = stack.pop();
        visited[currentRoom] = true;
        
        // Add all the keys in the current room to the stack
        for (const key of rooms[currentRoom]) {
            if (!visited[key]) {
                stack.push(key);
            }
        }
    }
    
    // Check if all rooms have been visited
    return visited.every(roomVisited => roomVisited);
};

// Test case 1
const rooms1 = [[1],[2],[3],[]];
const result1 = canVisitAllRooms(rooms1);
console.log("Test case 1:", result1); // Expected output: true

// Test case 2
const rooms2 = [[1,3],[3,0,1],[2],[0]];
const result2 = canVisitAllRooms(rooms2);
console.log("Test case 2:", result2); // Expected output: false


