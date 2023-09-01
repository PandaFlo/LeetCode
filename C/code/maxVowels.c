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


#include <stdio.h>
#include <string.h>

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(char *s, int k) {
    int maxVowelCount = 0;
    int currentVowelCount = 0;
    int length = strlen(s);

    // Count vowels in the first substring of length k
    for (int i = 0; i < k; ++i) {
        if (isVowel(s[i])) {
            currentVowelCount++;
        }
    }
    maxVowelCount = currentVowelCount;

    // Slide the window through the rest of the string
    for (int i = k; i < length; ++i) {
        if (isVowel(s[i - k])) {
            currentVowelCount--;
        }
        if (isVowel(s[i])) {
            currentVowelCount++;
        }
        if (currentVowelCount > maxVowelCount) {
            maxVowelCount = currentVowelCount;
        }
    }

    return maxVowelCount;
}

int main() {
    printf("%d\n", maxVowels("abciiidef", 3));   // Output: 3
    printf("%d\n", maxVowels("aeiou", 2));       // Output: 2
    printf("%d\n", maxVowels("leetcode", 3));   // Output: 2

    return 0;
}
