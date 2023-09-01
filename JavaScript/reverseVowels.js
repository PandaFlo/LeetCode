/* 
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

/**
 * @param {string} s
 * @return {string}
 */
// Function to reverse only the vowels in a string
var reverseVowels = function(s) {
    // Set of vowels (both lowercase and uppercase)
    const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    
    // Convert the string into an array of characters
    const chars = s.split('');
    
    // Initialize two pointers for traversing the string
    let left = 0;
    let right = s.length - 1;

    // Continue swapping vowels until the pointers meet or cross
    while (left < right) {
        // Move the left pointer until a vowel is found
        while (left < right && !vowels.has(chars[left])) {
            left++;
        }
        
        // Move the right pointer until a vowel is found
        while (left < right && !vowels.has(chars[right])) {
            right--;
        }

        // Swap the vowels at the left and right pointers
        if (left < right) {
            const temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
    }

    // Join the modified characters back into a string and return
    return chars.join('');
};

// Test cases
console.log(reverseVowels("hello")); // Output: "holle"
console.log(reverseVowels("leetcode")); // Output: "leotcede"

