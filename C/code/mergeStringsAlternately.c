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
char* mergeStrings(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int mergedLength = len1 + len2;
    
    // Allocate memory for the merged string
    char* merged = (char*)malloc((mergedLength + 1) * sizeof(char));
    int i = 0, j = 0, k = 0;
    
    // Merge the strings alternately
    while (i < len1 && j < len2) {
        merged[k++] = word1[i++];
        merged[k++] = word2[j++];
    }
    
    // Append the remaining characters from word1
    while (i < len1) {
        merged[k++] = word1[i++];
    }
    
    // Append the remaining characters from word2
    while (j < len2) {
        merged[k++] = word2[j++];
    }
    
    // Null-terminate the merged string
    merged[k] = '\0';
    
    return merged;
}

int main() {
    char word1[] = "abc";
    char word2[] = "pqr";
    
    // Merge the strings and print the result
    char* merged = mergeStrings(word1, word2);
    printf("Merged string: %s\n", merged);
    
    // Free the dynamically allocated memory
    free(merged);
    
    return 0;
}
