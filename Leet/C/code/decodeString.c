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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decodeString(char *s) {
  char *ret = calloc(300 * 30, sizeof(char));
  int slen = strlen(s);
  int retIdx = 0;
  int arrNum[15] = {0};
  int arrNumIdx = 0;
  int arrStr[15] = {0};
  int arrStrIdx = 0;

  for (int i = 0; i < slen; i++) {
    if (s[i] <= '9' && s[i] >= '0') {
      arrNum[arrNumIdx] = arrNum[arrNumIdx] * 10 + (s[i] - '0');
    } else if (s[i] <= 'z' && s[i] >= 'a') {
      ret[retIdx++] = s[i];
    } else if (s[i] == '[') {
      arrNumIdx++;
      arrStr[arrStrIdx++] = retIdx;
    } else if (s[i] == ']') {
      int right = retIdx;
      while (arrNum[arrNumIdx - 1] != 1) {
        for (int j = arrStr[arrStrIdx - 1]; j < right; j++) {
          ret[retIdx++] = ret[j];
        }
        arrNum[arrNumIdx - 1]--;
      }
      arrNumIdx--;
      arrStrIdx--;
      arrNum[arrNumIdx] = 0;
    }
  }
  return ret;
}
int main() {
    printf("%s\n", decodeString("3[a]2[bc]"));  // Output: "aaabcbc"
    printf("%s\n", decodeString("3[a2[c]]"));   // Output: "accaccacc"
    printf("%s\n", decodeString("2[abc]3[cd]ef"));  // Output: "abcabccdcdcdef"

    return 0;
}
