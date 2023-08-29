import java.util.ArrayList;
import java.util.List;

/**Given two strings, one is a subsequence if all of the elements of the first string occur in the same order within the second string. They do not have to be contiguous in the second string, but order must be maintained. For example, given the string 'I like cheese', the words ('I', 'cheese') are one possible subsequence of that string. Words are space delimited.
Given two strings, s and t, where t is a subsequence of s, report the words of s, missing in t (case sensitive), in the order they are missing.
Example
s = 'I like cheese'
t = 'like'
Then 'like' is the subsequence, and ['I', 'cheese'] is the list of missing words, in order.
Function Description
Complete the function missingWords in the editor below.
missingWords has the following parameter(s):
strings: a sentence of space-separated words string t: a sentence of space-separated words
Returns:
string[i]: an array of strings that contains all words in s that are missing from t, in the order they occur within s
Constraints
• Strings s and t consist of English alphabetic letters (i.e., a-z and A-Z), dash '-', and spaces only.
• All words are delimited by a space
·
1 ≤ /t/ ≤ /s/ ≤ 106
.
1 ≤ length of any word in s or t≤ 15
• It is guaranteed that string t is a subsequence of string s.
**/





public class MissingWords {
    public static List<String> missingWords(String s, String t) {
        List<String> result = new ArrayList<>();
        
        String[] sWords = s.split(" ");
        String[] tWords = t.split(" ");
        
        int tIndex = 0;
        for (int i = 0; i < sWords.length; i++) {
            if (tIndex < tWords.length && sWords[i].equals(tWords[tIndex])) {
                tIndex++;
            } else {
                result.add(sWords[i]);
            }
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        String s = "I like cheese";
        String t = "like";
        
        List<String> missing = missingWords(s, t);
        System.out.println(missing); // Output: [I, cheese]
    }
}
