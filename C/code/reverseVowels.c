
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

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// Function to check if a character is a vowel
bool isVowel(char c) {
    return c == 'a' || c == 'A' || c == 'E' || c == 'I' || c == 'O' ||
           c == 'U' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function to reverse vowels in a string
char *reverseVowels(char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    // Continue swapping vowels from both ends until left meets right
    while (left < right) {
        // Find the next vowel from the left
        while (left < right && !isVowel(s[left])) {
            left++;
        }
        // Find the next vowel from the right
        while (right > left && !isVowel(s[right])) {
            right--;
        }
        
        // Swap the vowels if found on both sides
        if (isVowel(s[left]) && isVowel(s[right])) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        } else {
            // If no vowels are found on one side, exit loop
            break;
        }
    }
    
    return s;
}

int main() {
    char input1[] = "hello";
    printf("Input: %s\n", input1);
    printf("Output: %s\n", reverseVowels(input1));

    char input2[] = "leetcode";
    printf("Input: %s\n", input2);
    printf("Output: %s\n", reverseVowels(input2));

    return 0;
}
