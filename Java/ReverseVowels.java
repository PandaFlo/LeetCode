
/**
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
**/



public class ReverseVowels {
    public String reverseVowels(String s) {
        char[] chars = s.toCharArray();
        int left = 0, right = chars.length - 1;
        String vowels = "aeiouAEIOU";

        // Move the left and right pointers towards each other until they meet.
        while (left < right) {
            // Find the next vowel from the left.
            while (left < right && vowels.indexOf(chars[left]) == -1) {
                left++;
            }
            // Find the next vowel from the right.
            while (left < right && vowels.indexOf(chars[right]) == -1) {
                right--;
            }

            // Swap the vowels found by the left and right pointers.
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;

            // Move the pointers inward.
            left++;
            right--;
        }

        // Return the string with reversed vowels.
        return new String(chars);
    }

    public static void main(String[] args) {
        ReverseVowels solution = new ReverseVowels();

        // Example 1
        String input1 = "hello";
        String output1 = solution.reverseVowels(input1);
        System.out.println(output1);  // Expected Output: "holle"

        // Example 2
        String input2 = "leetcode";
        String output2 = solution.reverseVowels(input2);
        System.out.println(output2);  // Expected Output: "leotcede"
    }
}
