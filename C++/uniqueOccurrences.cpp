/* Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000�� */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
                // Create a hash map to store occurrences of each value
        std::unordered_map<int, int> occurrences;

        // Populate the occurrences hash map
        for (int num : arr) {
            occurrences[num]++;
        }

        // Create a hash set to store unique occurrences
        std::unordered_set<int> unique;

        // Check for unique occurrences
        for (const auto& entry : occurrences) {
            if (unique.count(entry.second)) {
                return false; // Non-unique occurrence found
            }
            unique.insert(entry.second);
        }

        return true; // All occurrences are unique
    }
};

bool testUniqueOccurrences() {
    Solution solution;

    std::vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    if (!solution.uniqueOccurrences(arr1)) {
        return false;
    }

    std::vector<int> arr2 = {1, 2};
    if (solution.uniqueOccurrences(arr2)) {
        return false;
    }

    std::vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    if (!solution.uniqueOccurrences(arr3)) {
        return false;
    }

    return true;
}

int main() {
    bool testsPassed = testUniqueOccurrences();
    if (testsPassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
    return 0;
}
