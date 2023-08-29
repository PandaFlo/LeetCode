import java.util.ArrayList;
import java.util.List;

/**
 *You are given two strings word1 and word2. 
 Merge the strings by adding letters in alternating order, 
 starting with word1. If a string is longer than the other, 
 append the additional letters onto the end of the merged string.

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

**/


public class StringAlternateMerge2 {
    public static void main(String[] args) {
        // Input strings
        String word1 = "abc";
        String word2 = "defgh";

        // Merge the input strings alternately
        String merged = mergeAlternately(word1, word2);

        // Print the merged string
        System.out.println("Merged string: " + merged);
    }

    public static String mergeAlternately(String word1, String word2) {
        // Determine shorter and longer strings
        String shorter = word1;
        String longer = word2;
        if (word1.length() > word2.length()) {
            longer = word1;
            shorter = word2;
        } else {
            longer = word2;
            shorter = word1;
        }

        // Initialize the result string
        String result = "";

        // Iterate over indices of characters in shorter string
        for (int i = 0; i / 2 < shorter.length(); i++) {
            if (i % 2 == 0) {
                result += word1.charAt(i / 2); // Take a character from word1
            } else {
                result += word2.charAt(i / 2); // Take a character from word2
            }
        }

        // Append remaining characters from longer string if there's a length difference
        if (word1.length() != word2.length()) {
            result += longer.substring(shorter.length());
        }

        // Return the merged string
        return result;
    }
}
