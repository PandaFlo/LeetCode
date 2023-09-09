/* You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
 

Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
 */


 import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);
        List<List<String>> result = new ArrayList<>();
        String prefix = "";

        for (char c : searchWord.toCharArray()) {
            prefix += c;
            int index = binarySearch(products, prefix);
            List<String> suggestions = new ArrayList<>();
            
            for (int i = index; i < Math.min(index + 3, products.length); i++) {
                if (products[i].startsWith(prefix)) {
                    suggestions.add(products[i]);
                }
            }
            
            result.add(suggestions);
        }

        return result;
    }

    private int binarySearch(String[] products, String prefix) {
        int left = 0, right = products.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (products[mid].compareTo(prefix) < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
}

public class suggestedProducts {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        String[] products1 = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
        String searchWord1 = "mouse";
        List<List<String>> result1 = solution.suggestedProducts(products1, searchWord1);
        System.out.println("Test Case 1:");
        for (List<String> suggestions : result1) {
            for (String suggestion : suggestions) {
                System.out.print(suggestion + " ");
            }
            System.out.println();
        }

        // Test case 2
        String[] products2 = {"havana"};
        String searchWord2 = "havana";
        List<List<String>> result2 = solution.suggestedProducts(products2, searchWord2);
        System.out.println("Test Case 2:");
        for (List<String> suggestions : result2) {
            for (String suggestion : suggestions) {
                System.out.print(suggestion + " ");
            }
            System.out.println();
        }
    }
}
