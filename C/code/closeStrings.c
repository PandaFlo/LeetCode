/* Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.� */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool closeStrings(char *word1, char *word2) {
    int count1[26] = {0};
    int count2[26] = {0};
    int chars1[26] = {0};
    int chars2[26] = {0};

    for (int i = 0; word1[i] != '\0'; i++) {
        count1[word1[i] - 'a']++;
        chars1[word1[i] - 'a'] = 1;
    }

    for (int i = 0; word2[i] != '\0'; i++) {
        count2[word2[i] - 'a']++;
        chars2[word2[i] - 'a'] = 1;
    }

    for (int i = 0; i < 26; i++) {
        if ((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0)) {
            return false;
        }
    }

    // Sort the frequency arrays
    for (int i = 1; i < 26; i++) {
        for (int j = 0; j < 26 - i; j++) {
            if (count1[j] > count1[j + 1]) {
                int temp = count1[j];
                count1[j] = count1[j + 1];
                count1[j + 1] = temp;
            }

            if (count2[j] > count2[j + 1]) {
                int temp = count2[j];
                count2[j] = count2[j + 1];
                count2[j + 1] = temp;
            }
        }
    }

    // Compare the sorted frequency arrays
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;
}

void testCloseStrings() {
    printf("%d\n", closeStrings("abc", "bca"));       // Output: 1 (true)
    printf("%d\n", closeStrings("a", "aa"));         // Output: 0 (false)
    printf("%d\n", closeStrings("cabbba", "abbccc")); // Output: 1 (true)
    printf("%d\n", closeStrings("abbzccca", "babzzczc")); // Output: 1 (true)
}

int main() {
    testCloseStrings();
    return 0;
}
