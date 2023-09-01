/* Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000�� */


/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
        // Create an object to store occurrences of each value
        const occurrences = {};

        // Populate the occurrences object
        for (const num of arr) {
            occurrences[num] = (occurrences[num] || 0) + 1;
        }
    
        // Create a Set to store unique occurrences
        const unique = new Set();
    
        // Check for unique occurrences
        for (const count of Object.values(occurrences)) {
            if (unique.has(count)) {
                return false; // Non-unique occurrence found
            }
            unique.add(count);
        }
    
        return true; // All occurrences are unique
};

function testUniqueOccurrences() {
    const testCases = [
        { arr: [1, 2, 2, 1, 1, 3], expected: true },
        { arr: [1, 2], expected: false },
        { arr: [-3, 0, 1, -3, 1, 1, 1, -3, 10, 0], expected: true }
    ];

    for (const testCase of testCases) {
        const result = uniqueOccurrences(testCase.arr);
        console.log(`Input: [${testCase.arr}], Expected: ${testCase.expected}, Result: ${result}`);
    }
}

testUniqueOccurrences();
