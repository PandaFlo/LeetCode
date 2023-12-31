
/*
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.

*/



#include <stdio.h>
#include <string.h>


char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Ensure that len1 >= len2, swap if necessary
    if (len1 < len2) {
        return gcdOfStrings(str2, str1);
    }
    
    // If str2 is an empty string, str1 is the largest common divisor
    if (len2 == 0) {
        return str1;
    }
    
    // If the common prefix of str1 and str2 doesn't match, no common divisor exists
    if (strncmp(str1, str2, len2) != 0) {
        return "";
    }
    
    // Recursively search for the largest common divisor
    return gcdOfStrings(str1 + len2, str2);
}

int main() {
    char str1[] = "ABCABC";
    char str2[] = "ABC";
    
    char* result = gcdOfStrings(str1, str2);
    
    printf("Largest common divisor string: %s\n", result);
    
    return 0;
}