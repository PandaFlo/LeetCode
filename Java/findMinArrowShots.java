/* There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 

Constraints:

1 <= points.length <= 105
points[i].length == 2
-231 <= xstart < xend <= 231 - 1
 */


 import java.util.Arrays;


class Solution {
    public int findMinArrowShots(int[][] points) {
        
        int arrows = 1,n = points.length;
        long[] arr = new long[n];

        for(int i=0;i<n;i++){
            arr[i] = (((long)points[i][1])<<32) | (points[i][0]& 0xffff_ffffL);
        }
        Arrays.sort(arr);

        int end = (int) (arr[0]>>>32);

        for(int i=1;i<n;i++){
            int start = (int)(arr[i]& 0xffff_ffffL);
            if(start<=end){
                continue;
            }
            end = (int)(arr[i]>>>32);
            arrows++;
        }
        return arrows;

    }

}


public class findMinArrowShots {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        int[][] points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
        int result1 = solution.findMinArrowShots(points1);
        System.out.println("Test case 1 result: " + result1); // Expected output: 2

        // Test case 2
        int[][] points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
        int result2 = solution.findMinArrowShots(points2);
        System.out.println("Test case 2 result: " + result2); // Expected output: 4

        // Test case 3
        int[][] points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
        int result3 = solution.findMinArrowShots(points3);
        System.out.println("Test case 3 result: " + result3); // Expected output: 2
    }
}
