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

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int n = roomsSize;
    bool* visited = (bool*)malloc(n * sizeof(bool));
    
    // Initialize the visited array to all false
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    
    stack[++top] = 0; // Start with room 0
    visited[0] = true; // Mark room 0 as visited

    while (top >= 0) {
        int currentRoom = stack[top--];
        
        // Add all the keys in the current room to the stack
        for (int i = 0; i < roomsColSize[currentRoom]; i++) {
            int key = rooms[currentRoom][i];
            if (!visited[key]) {
                stack[++top] = key;
                visited[key] = true; // Mark the room as visited
            }
        }
    }
    
    // Check if all rooms have been visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            free(visited);
            free(stack);
            return false; // There is an unvisited room
        }
    }
    
    free(visited);
    free(stack);
    return true; // All rooms have been visited
}

int main() {
    // Test case 1
    int room1[] = {1};
    int* rooms1[] = {room1};
    int roomsColSize1[] = {1};
    bool result1 = canVisitAllRooms(rooms1, 1, roomsColSize1);
    printf("Test case 1: %s\n", result1 ? "true" : "false"); // Expected output: true

    // Test case 2
    int room2_1[] = {1, 3};
    int room2_2[] = {3, 0, 1};
    int room2_3[] = {2};
    int room2_4[] = {0};
    int* rooms2[] = {room2_1, room2_2, room2_3, room2_4};
    int roomsColSize2[] = {2, 3, 1, 1};
    bool result2 = canVisitAllRooms(rooms2, 4, roomsColSize2);
    printf("Test case 2: %s\n", result2 ? "true" : "false"); // Expected output: false

    return 0;
}
