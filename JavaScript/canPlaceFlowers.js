/* 
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
*/

/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */

var canPlaceFlowers = function(flowerbed, n) {
    let count = 0; // Count of available spots to plant flowers
    let i = 0;

    while (i < flowerbed.length) {
        if (flowerbed[i] === 0) {
            // Check if the previous and next positions are also empty
            const prevEmpty = i === 0 || flowerbed[i - 1] === 0;
            const nextEmpty = i === flowerbed.length - 1 || flowerbed[i + 1] === 0;

            if (prevEmpty && nextEmpty) {
                // Plant a flower and decrement n
                flowerbed[i] = 1;
                count++;
                n--;
            }
        }

        i++;
    }

    return n <= 0; // Return true if all required flowers are planted
};

// Test cases
console.log(canPlaceFlowers([1,0,0,0,1], 1)); // Output: true
console.log(canPlaceFlowers([1,0,0,0,1], 2)); // Output: false

