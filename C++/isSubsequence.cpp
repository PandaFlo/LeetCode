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


#include <iostream>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int sPointer = 0; // Pointer for string s
        int tPointer = 0; // Pointer for string t
        
        while (sPointer < s.length() && tPointer < t.length()) {
            if (s[sPointer] == t[tPointer]) {
                sPointer++; // Move the pointer in string s
            }
            tPointer++; // Move the pointer in string t
        }
        
        // If the entire s has been traversed, it is a subsequence
        return sPointer == s.length();
    }
};

int main() {
    Solution solution;
    
    std::string s1 = "abc";
    std::string t1 = "ahbgdc";
    std::cout << solution.isSubsequence(s1, t1) << std::endl; // Output: 1 (true)
    
    std::string s2 = "axc";
    std::string t2 = "ahbgdc";
    std::cout << solution.isSubsequence(s2, t2) << std::endl; // Output: 0 (false)
    
    return 0;
}
