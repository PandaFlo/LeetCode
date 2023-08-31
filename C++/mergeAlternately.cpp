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






#include <iostream>
#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string merged;
        int i = 0, j = 0;
        
        // Alternate between characters from word1 and word2 until one of them is exhausted
        while (i < word1.length() && j < word2.length()) {
            merged += word1[i++]; // Add character from word1
            merged += word2[j++]; // Add character from word2
        }
        
        // Append remaining characters from word1 if any
        while (i < word1.length()) {
            merged += word1[i++];
        }
        
        // Append remaining characters from word2 if any
        while (j < word2.length()) {
            merged += word2[j++];
        }
        
        return merged;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    std::string word1 = "abc";
    std::string word2 = "pqr";
    std::string merged1 = solution.mergeAlternately(word1, word2);
    std::cout << "Merged 1: " << merged1 << std::endl;

    std::string word3 = "ab";
    std::string word4 = "pqrs";
    std::string merged2 = solution.mergeAlternately(word3, word4);
    std::cout << "Merged 2: " << merged2 << std::endl;

    std::string word5 = "abcd";
    std::string word6 = "pq";
    std::string merged3 = solution.mergeAlternately(word5, word6);
    std::cout << "Merged 3: " << merged3 << std::endl;
    
    return 0;
}

