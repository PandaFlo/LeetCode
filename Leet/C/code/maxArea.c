/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

 */


#include <stdio.h>

#include <math.h>
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;
    
    while (left < right) {
        int h = fmin(height[left], height[right]); // Choose the minimum height
        int width = right - left;
        int area = h * width;
        maxArea = fmax(maxArea, area);
        
        if (height[left] < height[right]) {
            left++; // Move the left pointer to the right
        } else {
            right--; // Move the right pointer to the left
        }
    }
    
    return maxArea;
}

int main() {
    int height1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize1 = sizeof(height1) / sizeof(height1[0]);
    int result1 = maxArea(height1, heightSize1);
    printf("Max Area 1: %d\n", result1);

    int height2[] = {1, 1};
    int heightSize2 = sizeof(height2) / sizeof(height2[0]);
    int result2 = maxArea(height2, heightSize2);
    printf("Max Area 2: %d\n", result2);

    return 0;
}

