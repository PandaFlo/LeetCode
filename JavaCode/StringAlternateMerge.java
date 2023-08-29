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
        String word1 = "abc";
        String word2 = "defgh";

        String merged = mergeAlternately(word1, word2);
        System.out.println("Merged string: " + merged);
    }

    public static String mergeAlternately(String word1, String word2) {
        int size = word1.length() + word2.length();
        StringBuilder result = new StringBuilder();
        int count = 0;
        
        while (result.length() != size) {
            if (count < word1.length()) {
                result.append(word1.charAt(count));
            }
            if (count < word2.length()) {
                result.append(word2.charAt(count));
            }
            count++;
        }
        
        return result.toString();
    }
}
