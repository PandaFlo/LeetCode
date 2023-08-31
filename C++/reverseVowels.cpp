/*

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.

*/






#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0; // Pointer to the leftmost character
        int right = s.length() - 1; // Pointer to the rightmost character
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; // Set of vowels
        
        while (left < right) {
            // Move the left pointer until a vowel is found
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            
            // Move the right pointer until a vowel is found
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            
            // Swap the vowels at left and right pointers
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    string s1 = "hello";
    cout << "Input 1: " << s1 << ", Output 1: " << solution.reverseVowels(s1) << endl;
    
    // Example 2
    string s2 = "leetcode";
    cout << "Input 2: " << s2 << ", Output 2: " << solution.reverseVowels(s2) << endl;
    
    return 0;
}
