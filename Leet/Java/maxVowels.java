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

class Solution{

    public static int maxVowels(String s, int k) {
        int maxVowelCount = 0;
        int currentVowelCount = 0;

        for (int i = 0; i < k; ++i) {
            if (isVowel(s.charAt(i))) {
                currentVowelCount++;
            }
        }
        maxVowelCount = currentVowelCount;

        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s.charAt(i - k))) {
                currentVowelCount--;
            }
            if (isVowel(s.charAt(i))) {
                currentVowelCount++;
            }
            maxVowelCount = Math.max(maxVowelCount, currentVowelCount);
        }

        return maxVowelCount;
    }

    private static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

}



public class maxVowels { 
   
    public static void main(String[] args) {
        System.out.println(Solution.maxVowels("abciiidef", 3));   // Output: 3
        System.out.println(Solution.maxVowels("aeiou", 2));       // Output: 2
        System.out.println(Solution.maxVowels("leetcode", 3));   // Output: 2
    }
}
