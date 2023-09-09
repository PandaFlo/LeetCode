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


#include <vector>
#include <string>
#include <algorithm>
#include <iostream>




class Solution {
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord) {
        std::sort(products.begin(), products.end());
        std::vector<std::vector<std::string>> res;
        std::string prefix = "";
        int i = 0;

        for (char c : searchWord) {
            prefix += c;
            i = std::lower_bound(products.begin() + i, products.end(), prefix) - products.begin();
            std::vector<std::string> suggestions;
            
            for (int j = i; j < std::min(i + 3, static_cast<int>(products.size())); j++) {
                if (products[j].find(prefix) == 0) {
                    suggestions.push_back(products[j]);
                }
            }
            
            res.push_back(suggestions);
        }
        
        return res;
    }
};


int main() {
    Solution solution;

    // Test case 1
    std::vector<std::string> products1 = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    std::string searchWord1 = "mouse";
    std::vector<std::vector<std::string>> result1 = solution.suggestedProducts(products1, searchWord1);
    std::cout << "Test Case 1:" << std::endl;
    for (const std::vector<std::string>& suggestions : result1) {
        for (const std::string& suggestion : suggestions) {
            std::cout << suggestion << " ";
        }
        std::cout << std::endl;
    }

    // Test case 2
    std::vector<std::string> products2 = {"havana"};
    std::string searchWord2 = "havana";
    std::vector<std::vector<std::string>> result2 = solution.suggestedProducts(products2, searchWord2);
    std::cout << "Test Case 2:" << std::endl;
    for (const std::vector<std::string>& suggestions : result2) {
        for (const std::string& suggestion : suggestions) {
            std::cout << suggestion << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

