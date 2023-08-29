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


public class StringAlternateMerge {
    public static void main(String[] args) {
        // Input strings to be merged alternately
        String word1 = "abc";
        String word2 = "defgh";

        // Merge the input strings alternately
        String merged = mergeAlternately(word1, word2);
        
        // Print the merged string
        System.out.println("Merged string: " + merged);
    }

    /**
     * Merges two input strings alternately character by character.
     *
     * @param word1 The first input string
     * @param word2 The second input string
     * @return A string containing characters merged alternately from both input strings
     */
    public static String mergeAlternately(String word1, String word2) {
        // Calculate the total size of the merged string
        int size = word1.length() + word2.length();
        StringBuilder result = new StringBuilder(); // To store the merged result
        int count = 0; // Counter for tracking the current position in the strings
        
        // Continue merging until the result size matches the calculated size
        while (result.length() != size) {
            // Append a character from word1 if available
            if (count < word1.length()) {
                result.append(word1.charAt(count));
            }
            
            // Append a character from word2 if available
            if (count < word2.length()) {
                result.append(word2.charAt(count));
            }
            
            count++; // Move to the next position in the strings
        }
        
        return result.toString(); // Return the merged result
    }
}