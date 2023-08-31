/*

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

*/






#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s); // Create a stringstream to tokenize the input string
        vector<string> words; // Vector to store individual words
        
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Build the reversed string by joining words in reverse order
        string reversed;
        for (int i = words.size() - 1; i >= 0; --i) {
            reversed += words[i];
            if (i != 0) {
                reversed += " ";
            }
        }
        
        return reversed;
    }
};

int main() {
    Solution solution;
    
    string s1 = "the sky is blue";
    cout << "Input 1: " << s1 << ", Output 1: " << solution.reverseWords(s1) << endl;
    
    string s2 = "  hello world  ";
    cout << "Input 2: " << s2 << ", Output 2: " << solution.reverseWords(s2) << endl;
    
    string s3 = "a good   example";
    cout << "Input 3: " << s3 << ", Output 3: " << solution.reverseWords(s3) << endl;
    
    return 0;
}
