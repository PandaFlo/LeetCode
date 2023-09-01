/* Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length */


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
    int maxVowels(string s, int k) {
        int n = s.length();
        int i = 0 ,j = 0;
        int max_vowel = 0;

        while(j<n){
            i+= vowels[s[j]-'a'];

            if(j>=k){
                i-= vowels[s[j-k]-'a'];
            }
            max_vowel = max(max_vowel,i);
            j++;
        }

        return max_vowel;

    }
};

int main() {
    Solution solution;
    cout << solution.maxVowels("abciiidef", 3) << endl;  // Output: 3
    cout << solution.maxVowels("aeiou", 2) << endl;      // Output: 2
    cout << solution.maxVowels("leetcode", 3) << endl;  // Output: 2

    return 0;
}
