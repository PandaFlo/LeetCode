
/*
There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

 

Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
 

Constraints:

n == candies.length
2 <= n <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50

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
