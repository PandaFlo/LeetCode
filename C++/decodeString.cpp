/* Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
 */




#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string currStr = "";
        int currNum = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";
            } else if (c == ']') {
                int repeat = numStack.top();
                numStack.pop();
                string prevStr = strStack.top();
                strStack.pop();
                string repeatedStr = "";
                for (int i = 0; i < repeat; i++) {
                    repeatedStr += currStr;
                }
                currStr = prevStr + repeatedStr;
            } else {
                currStr += c;
            }
        }
        
        return currStr;
    }
};

int main() {
    Solution solution;

    // Test cases
    cout << solution.decodeString("3[a]2[bc]") << endl;  // Output: "aaabcbc"
    cout << solution.decodeString("3[a2[c]]") << endl;   // Output: "accaccacc"
    cout << solution.decodeString("2[abc]3[cd]ef") << endl;  // Output: "abcabccdcdcdef"

    return 0;
}
