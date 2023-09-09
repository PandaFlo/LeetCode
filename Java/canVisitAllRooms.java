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

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;


class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] visited = new boolean[n];
        
        // Use a stack to keep track of the rooms to visit
        Stack<Integer> stack = new Stack<>();
        stack.push(0); // Start with room 0
        
        while (!stack.isEmpty()) {
            int currentRoom = stack.pop();
            visited[currentRoom] = true;
            
            // Add all the keys in the current room to the stack
            for (int key : rooms.get(currentRoom)) {
                if (!visited[key]) {
                    stack.push(key);
                }
            }
        }
        
        // Check if all rooms have been visited
        for (boolean roomVisited : visited) {
            if (!roomVisited) {
                return false; // There is an unvisited room
            }
        }
        
        return true; // All rooms have been visited
    }
}



public class canVisitAllRooms {
    public static void main(String[] args) {
        // Test case 1
        List<List<Integer>> rooms1 = new ArrayList<>();
        rooms1.add(Arrays.asList(1));
        rooms1.add(Arrays.asList(2));
        rooms1.add(Arrays.asList(3));
        rooms1.add(new ArrayList<>());

        Solution solution = new Solution();
        boolean result1 = solution.canVisitAllRooms(rooms1);
        System.out.println("Test case 1: " + result1); // Expected output: true

        // Test case 2
        List<List<Integer>> rooms2 = new ArrayList<>();
        rooms2.add(Arrays.asList(1, 3));
        rooms2.add(Arrays.asList(3, 0, 1));
        rooms2.add(Arrays.asList(2));
        rooms2.add(Arrays.asList(0));

        boolean result2 = solution.canVisitAllRooms(rooms2);
        System.out.println("Test case 2: " + result2); // Expected output: false
    }
}

