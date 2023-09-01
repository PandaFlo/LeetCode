/* Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
 */


#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char *s, char *t) {
    while (*s != '\0' && *t != '\0') {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    return (*s == '\0'); // If s reached the end, it's a subsequence.
}

int main() {
    char *s1 = "abc";
    char *t1 = "ahbgdc";
    printf("Test 1: %s\n", isSubsequence(s1, t1) ? "true" : "false");

    char *s2 = "axc";
    char *t2 = "ahbgdc";
    printf("Test 2: %s\n", isSubsequence(s2, t2) ? "true" : "false");

    return 0;
}
