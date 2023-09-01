/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to merge two strings alternately
char* mergeAlternately(char* word1, char* word2) {
    // Calculate the total length of the merged string
    int length = strlen(word1) + strlen(word2);
    
    // Allocate memory for the merged string
    char* str = malloc(sizeof(char) * length + 1);
    
    // Initialize an index for iterating through the merged string
    int i;
    
    // Loop through both input strings alternately
    for (i = 0; i < length;) {
        // Append characters from word1 if available
        if (*word1) {
            str[i++] = *word1++;
        }
        
        // Append characters from word2 if available
        if (*word2) {
            str[i++] = *word2++;
        }
    }
    
    // Null-terminate the merged string
    str[length] = '\0';
    
    // Return the merged string
    return str;
    
    // NOTE: The code below won't be executed due to the return statement
    // Free the dynamically allocated memory (this code will never be reached)
    free(str);
}


int main() {
    char word1[] = "abc";
    char word2[] = "pqr";
    
    // Merge the strings and print the result
    char* merged = mergeAlternately(word1, word2);
    printf("Merged string: %s\n", merged);
    
    // Free the dynamically allocated memory
    free(merged);
    
    return 0;
}
