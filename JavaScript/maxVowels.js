/* Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length */


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxVowels = function(s, k) {
    const isVowel = (c) => {
        return c === 'a' || c === 'e' || c === 'i' || c === 'o' || c === 'u';
    };

    let maxVowelCount = 0;
    let currentVowelCount = 0;

    // Count vowels in the first substring of length k
    for (let i = 0; i < k; ++i) {
        if (isVowel(s[i])) {
            currentVowelCount++;
        }
    }
    maxVowelCount = currentVowelCount;

    // Slide the window through the rest of the string
    for (let i = k; i < s.length; ++i) {
        if (isVowel(s[i - k])) {
            currentVowelCount--;
        }
        if (isVowel(s[i])) {
            currentVowelCount++;
        }
        maxVowelCount = Math.max(maxVowelCount, currentVowelCount);
    }

    return maxVowelCount;
};

console.log(maxVowels("abciiidef", 3));   // Output: 3
console.log(maxVowels("aeiou", 2));       // Output: 2
console.log(maxVowels("leetcode", 3));   // Output: 2
