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
#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (a < b ? a : b)

int cmpfun(const void * a, const void * b)
{
    if(((int **)a)[0][1] > ((int **)b)[0][1]) return 1;
    else if(((int **)a)[0][1] < ((int **)b)[0][1]) return -1;
    return 0;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){

    qsort(points, pointsSize, sizeof(int*), cmpfun);
    
    int ans = 1, minval = *(*(points) + 1);
    
    for(int i = 1; i < pointsSize; ++i)
    {
        if(*(*(points + i)) > minval)
        {
            ans++;
            minval = *(*(points + i) + 1);
        }
        else
        {
            minval = min(minval, *(*(points + i) + 1));
        }
    }
    return ans;
}

int main() {
    int points1[][2] = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int points2[][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    int points3[][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};

    int *pointsArray1[] = {points1[0], points1[1], points1[2], points1[3]};
    int *pointsArray2[] = {points2[0], points2[1], points2[2], points2[3]};
    int *pointsArray3[] = {points3[0], points3[1], points3[2], points3[3]};

    int pointsSize1 = sizeof(pointsArray1) / sizeof(pointsArray1[0]);
    int pointsSize2 = sizeof(pointsArray2) / sizeof(pointsArray2[0]);
    int pointsSize3 = sizeof(pointsArray3) / sizeof(pointsArray3[0]);

    int pointsColSize1 = sizeof(pointsArray1[0]) / sizeof(pointsArray1[0][0]);
    int pointsColSize2 = sizeof(pointsArray2[0]) / sizeof(pointsArray2[0][0]);
    int pointsColSize3 = sizeof(pointsArray3[0]) / sizeof(pointsArray3[0][0]);

    int result1 = findMinArrowShots(pointsArray1, pointsSize1, &pointsColSize1);
    int result2 = findMinArrowShots(pointsArray2, pointsSize2, &pointsColSize2);
    int result3 = findMinArrowShots(pointsArray3, pointsSize3, &pointsColSize3);

    printf("Result 1: %d\n", result1); // Output: 2
    printf("Result 2: %d\n", result2); // Output: 4
    printf("Result 3: %d\n", result3); // Output: 2

    return 0;
}

