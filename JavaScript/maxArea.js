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


/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let maxWater = 0;
    let left = 0;
    let right = height.length - 1;

    while (left < right) {
        const hLeft = height[left];
        const hRight = height[right];
        const width = right - left;
        const minHeight = Math.min(hLeft, hRight);
        const area = width * minHeight;

        maxWater = Math.max(maxWater, area);

        if (hLeft < hRight) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
};

// Test the maxArea function with examples
const example1 = [1, 8, 6, 2, 5, 4, 8, 3, 7];
const example2 = [1, 1];

const result1 = maxArea(example1);
const result2 = maxArea(example2);

console.log("Example 1: ", result1); // Output: 49
console.log("Example 2: ", result2); // Output: 1


