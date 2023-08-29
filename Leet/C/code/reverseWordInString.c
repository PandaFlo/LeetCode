
/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Function to check if a character is a space, tab, or newline
int is_space(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// Function to reverse the order of words in a string
char *reverseWords(char *s) {
    char *out;   // Resultant string
    int len;     // Length of the input string
    int flag;    // Flag to indicate if a word has been encountered
    int j;       // Index for the output string
    int k;       // Index for traversing a word in the input string

    len = strlen(s);
    out = malloc(sizeof(char) * len + 1); // Allocate memory for the output string
    if (!out)
        return (0);  // Return null if memory allocation fails
    len--;           // Adjust length to 0-based index
    flag = 0;        // Initialize the word encountered flag
    j = 0;           // Initialize index for the output string

    // Loop to process each character in the input string
    while (len >= 0) {
        // Skip trailing spaces, tabs, and newlines
        if (is_space(s[len]))
            len--;
        else {
            // A non-space character indicates the start of a word
            while (len >= 0 && !is_space(s[len]))
                len--;  // Traverse to the end of the current word

            if (flag)
                out[j++] = ' ';  // Add a space before a word (except the first word)
            else
                flag = 1;        // Set the flag to indicate a word has been encountered

            k = 1;
            // Copy the word to the output string in reverse order
            while (s[len + k] && s[len + k] && !is_space(s[len + k]))
                out[j++] = s[len + k++];
        }
    }
    out[j] = 0;  // Null-terminate the output string
    return (out);  // Return the reversed string
}


int main() {
    char s[] = "a good   example";
    char *reversed = reverseWords(s);
    printf("%s\n", reversed);
    return 0;
}
