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
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// Function to compare strings for sorting
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

char ***suggestedProducts(char **products, int productsSize, char *searchWord, int *returnSize, int **returnColumnSizes) {
    // Sort the products array lexicographically
    qsort(products, productsSize, sizeof(char*), compareStrings);

    int searchWordLen = strlen(searchWord);
    char ***result = (char ***)malloc(searchWordLen * sizeof(char **));
    *returnColumnSizes = (int *)malloc(searchWordLen * sizeof(int));
    *returnSize = searchWordLen;

    char prefix[searchWordLen + 1];
    prefix[0] = '\0';

    for (int i = 0; i < searchWordLen; i++) {
        prefix[i] = searchWord[i];
        prefix[i + 1] = '\0';

        char **suggestions = (char **)malloc(productsSize * sizeof(char *));
        int count = 0;

        for (int j = 0; j < productsSize; j++) {
            if (strncmp(prefix, products[j], i + 1) == 0) {
                // Check if the product matches the prefix
                suggestions[count++] = strdup(products[j]);
            }

            if (count == 3) {
                // Limit the suggestions to a maximum of 3
                break;
            }
        }

        (*returnColumnSizes)[i] = count;
        result[i] = (char **)malloc(count * sizeof(char *));

        for (int k = 0; k < count; k++) {
            result[i][k] = suggestions[k];
        }

        free(suggestions);
    }

    return result;
}



int main() {
    char *products[] = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    int productsSize = 5;
    char searchWord[] = "mouse";

    int returnSize;
    int *returnColumnSizes;
    char ***result = suggestedProducts(products, productsSize, searchWord, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("Suggestions for prefix '%c':\n", searchWord[i]);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s\n", result[i][j]);
            free(result[i][j]);  // Free each suggestion
        }
        free(result[i]);  // Free the array of suggestions
    }

    free(result);  // Free the main result array
    free(returnColumnSizes);

    return 0;
}
